/*
** EPITECH PROJECT, 2021
** MYFTP
** File description:
** le FTP
*/

#include "include.h"

int init_the_pas(the_client_t *client)
{
    struct sockaddr_in *sock_in = malloc(sizeof(struct sockaddr_in));
    socklen_t size = sizeof(sock_in);
    struct sockaddr_in* pV4Addr;
    struct in_addr ipAddr;;

    sock_in->sin_port = htons(0);
    sock_in->sin_family = AF_INET;
    sock_in->sin_addr.s_addr = INADDR_ANY;
    bind(client->fd_md, (const struct sockaddr *)sock_in, sizeof(*sock_in));
    listen(client->fd_md, 1);
    getsockname(client->fd_md, (struct sockaddr *)sock_in, &size);
    client->pass_port = ntohs(sock_in->sin_port);

    pV4Addr = (struct sockaddr_in*)&sock_in;
    ipAddr = pV4Addr->sin_addr;
    client->ip = malloc(sizeof(char) * INET_ADDRSTRLEN);
    inet_ntop( AF_INET, &ipAddr, client->ip, INET_ADDRSTRLEN );
    return 0;
}

int run_pasv(soc_t *socket_server, the_client_t *client, struct protoent *protoent_pas_long)
{
    if (client->fd_md != -1)
        close(client->fd_md);
    protoent_pas_long = getprotobyname("TCP");
    if(protoent_pas_long == NULL)
        return (1);
    client->fd_md = socket(AF_INET, SOCK_STREAM, protoent_pas_long->p_proto);
    init_the_pas(client);
    return 0;
}

void pasv_option(char **double_tab, char *clean_listen, soc_t *socket_server, the_client_t *client){
    struct protoent *protoent_pas_long = NULL;
    char *one_ip;
    char **double_ip;

    if(strcmp("PASV\n", double_tab[0]) == 0 || strcmp("PASV", double_tab[0]) == 0){
        switch(client->log){
            case 0:
                dprintf(client->fd, "530 Please login with USER and PASS.\n");
                break;
            case 1:
                run_pasv(socket_server, client, protoent_pas_long);
                client->pass_mod = 1;
                double_ip = create_double_tabs_ip(client->ip);
                dprintf(client->fd, "227 Entering Passive Mode (");
                for(int par = 0; double_ip[par]; par++)
                    dprintf(client->fd, "%s,",  double_ip[par]);
                dprintf(client->fd, "%d, %d).\n", client->pass_port / 256, client->pass_mod % 256);
                free(double_ip);
                free(double_ip);
                break;
        }
    }
}