/*
** EPITECH PROJECT, 2021
** MYFTP
** File description:
** le ftp
*/

#include "include.h"

void quit_option(char **double_tab, char *clean_listen, soc_t *socket_server, the_client_t *client)
{
    if(strcmp("QUIT\n", double_tab[0]) == 0 || strcmp("QUIT", double_tab[0]) == 0){
        dprintf(client->fd, "221 Goodbye.\n");
        client->quit = -1;
    }
}
