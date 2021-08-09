/*
** EPITECH PROJECT, 2021
** MYFTP
** File description:
** le FTP
*/

#include "include.h"

void login_mdp_database(char **double_tab, char *clean_listen, soc_t *socket_server, the_client_t *client)
{
    if(strcmp("Anonymous\n", client->usrnm) == 0){
        client->log = 1;
        dprintf(client->fd, "230 Login successful.\n");
        return;
    }
    if(strcmp("Anonymous\n", client->usrnm) == 0 && strcmp("nothing", client->psswrd) == 0){
        client->log = 1;
        dprintf(client->fd, "230 Login successful.\n");
    }
}

void pass_option(char **double_tab, char *clean_listen, soc_t *socket_server, the_client_t *client)
{
    int len_double_tab = 0;

    for(; double_tab[len_double_tab]; len_double_tab++);
    if(strcmp(double_tab[0], "PASS") == 0 && client->log == 1)
        dprintf(client->fd, "230 Already logged in.\n");
    if(strcmp(double_tab[0], "PASS") == 0 && client->log == 0){
        client->psswrd = malloc(sizeof(char) * strlen(double_tab[1]));
        strcpy(client->psswrd, double_tab[1]);
        login_mdp_database(double_tab, clean_listen, socket_server, client);
    }
    if(strcmp(double_tab[0], "PASS\n") == 0){
        client->psswrd = malloc(sizeof(char) * strlen("nothing") + 1);
        strcpy(client->psswrd, "nothing");
        login_mdp_database(double_tab, clean_listen, socket_server, client);
    }
}