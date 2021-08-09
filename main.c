/*
** EPITECH PROJECT, 2021
** MYFTP
** File description:
** le ftp
*/

#include "include.h"

void in_the_fork(the_client_t client, char *clean_listen, \
soc_t *socket_server, struct sockaddr_in el_client_bg){
    init_client(&client, socket_server, el_client_bg);
    while (2){
        if (client.quit == -1)
            break;
        memset(clean_listen, 0, sizeof(clean_listen));
        dirty_hand(clean_listen, client);
        hub_function(clean_listen, socket_server, &client);
        if (client.quit == -1)
            exit(0);
    }
}

void select_parcour(soc_t *socket_server, char *clean_listen, struct sockaddr_in el_client_bg)
{
    socklen_t taille = sizeof(socket_server->server_address);
    the_client_t client;

    for (int i = 0; i < FD_SETSIZE; i++)
        if (FD_ISSET(i, &socket_server->ready_sockets)){
            if (i == socket_server->socket_p){
                socket_server->client_socket = \
accept(socket_server->socket_p, (struct sockaddr*) &el_client_bg, &taille);
                FD_SET(socket_server->client_socket, &socket_server->current_sockets);
                init_client(&client, socket_server, el_client_bg);
                dprintf(client.fd, "220 (vsFTPd 3.0.0)\n");
            }
            else {
                if (socket_server->client_socket == -1)
                    exit(84);
                if (fork() == 0)
                    in_the_fork(client, clean_listen, socket_server, el_client_bg);
                else
                    close(socket_server->client_socket);
                FD_CLR(i, &socket_server->current_sockets);
            }
        }
}

int boucle_server(soc_t *socket_server)
{
    struct sockaddr_in el_client_bg;
    socklen_t taille = sizeof(socket_server->server_address);
    the_client_t client;
    char *clean_listen = malloc(sizeof(char));

    FD_ZERO(&socket_server->current_sockets);
    FD_SET(socket_server->socket_p, &socket_server->current_sockets);
    while (1){
        socket_server->ready_sockets = socket_server->current_sockets;
        if(select(FD_SETSIZE, &socket_server->ready_sockets, NULL, NULL, NULL) < 0){
            perror("select est pas beau");
            exit(84);
        }
        select_parcour(socket_server, clean_listen, el_client_bg);
    }
}

int main(int argc, char **argv)
{
    soc_t socket_server;

    if (strcmp("-h", argv[1]) == 0){
        print_the_help();
        return 0;
    }
    if (define_the_serv(argv, &socket_server) == 84)
        return 84;
    
    if (boucle_server(&socket_server) == -1)
        return 84;
    return 0;
}

/*ameliorer pwd, carré et c'est carrée*/