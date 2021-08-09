/*
** EPITECH PROJECT, 2021
** MYFTP
** File description:
** le ftp
*/

#include "include.h"

void noop_option(char **double_tab, char *clean_listen, \
soc_t *socket_server, the_client_t *client){
    if (strcmp("NOOP\n", double_tab[0]) == 0 || strcmp("NOOP", double_tab[0]) == 0){
        switch(client->log){
            case 0:
                dprintf(client->fd, "530 Please login with USER and PASS.\n");
                break;
            case 1:
                dprintf(client->fd, "200 NOOP ok.\n");
                break;
        }
    }
}

void hub_function(char *clean_listen, soc_t *socket_server, the_client_t *client)
{
    char **double_tab = create_double_tabs(clean_listen);

    user_option(double_tab, clean_listen, socket_server, client);
    pass_option(double_tab, clean_listen, socket_server, client);
    help_option(double_tab, clean_listen, socket_server, client);
    pwd_option(double_tab, clean_listen, socket_server, client);
    quit_option(double_tab, clean_listen, socket_server, client);
    pasv_option(double_tab, clean_listen, socket_server, client);
    noop_option(double_tab, clean_listen, socket_server, client);
}