/*
** EPITECH PROJECT, 2021
** MYFTP
** File description:
** le ftp
*/

#include "include.h"

int define_the_serv(char **argv, soc_t *socket_server)
{
    int el_proto;
    if(chdir(argv[2]) == -1)
        return 84;
    socket_server->the_path = malloc(strlen(argv[2]) * sizeof(char));
    strcpy(socket_server->the_path, argv[2]);
    socket_server->the_protocole = getprotobyname("TCP");
    el_proto = socket_server->the_protocole->p_proto;
    socket_server->socket_p = socket(AF_INET, SOCK_STREAM, el_proto);
    socket_server->server_address.sin_family = AF_INET;
    socket_server->server_address.sin_port = htons(atoi(argv[1]));
    socket_server->server_address.sin_addr.s_addr = INADDR_ANY;
    bind(socket_server->socket_p, \
    (const struct sockaddr*) &socket_server->server_address, \
    sizeof(socket_server->server_address));
    listen(socket_server->socket_p, 50);
    return 0;
}

void init_client(the_client_t *client, soc_t *socket_server, struct sockaddr_in el_client_bg)
{
    client->pass_port = 0;
    client->pass_mod = 0;
    client->fd_md = -1;
    client->fd = socket_server->client_socket;
    client->log = 0;
    client->quit = 1;
    client->ip = malloc(sizeof(char) * 20);
    strcpy(client->ip, inet_ntoa(el_client_bg.sin_addr));
}