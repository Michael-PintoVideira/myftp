/*
** EPITECH PROJECT, 2021
** MYFTP
** File description:
** le FTP
*/

#include "include.h"

void pwd_option(char **double_tab, char *clean_listen, soc_t *socket_server, the_client_t *client){
    char *path;

    if(strcmp("PWD\n", double_tab[0]) == 0 || strcmp("PWD", double_tab[0]) == 0){
        switch(client->log){
            case 0:
                dprintf(client->fd, "530 Please login with USER and PASS.\n");
                break;
            case 1:
                path = malloc(sizeof(char) * 150);
                if(strcmp(".", socket_server->the_path) == 0){
                    getcwd(path, 150);
                    dprintf(client->fd, path);
                    dprintf(client->fd, "\n");
                    free(path);
                }
                else{
                    dprintf(client->fd, socket_server->the_path);
                    dprintf(client->fd, "\n");
                }
                break;
        }
    }
}