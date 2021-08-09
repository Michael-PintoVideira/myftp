#include "include.h"

void define_username(char **double_tab, char *clean_listen, soc_t *socket_server, the_client_t *client, int len_double_tab)
{
    if(len_double_tab > 1 && strcmp(double_tab[0], "USER") == 0 && client->log == 0){
        client->usrnm = malloc(sizeof(char) * strlen(double_tab[1]));
        strcpy(client->usrnm, double_tab[1]);
        dprintf(client->fd, "331 Please specify the password.\n");
    }
}

void user_option(char **double_tab, char *clean_listen, soc_t *socket_server, the_client_t *client)
{
    int len_double_tab = 0;

    for(; double_tab[len_double_tab]; len_double_tab++);
    if(len_double_tab == 1 && strcmp(double_tab[0], "USER\n") == 0 && client->log == 0)
        dprintf(client->fd, "530 Permission denied.\n");
    /*mettre les options user ici */
    define_username(double_tab, clean_listen, socket_server, client, len_double_tab);
}