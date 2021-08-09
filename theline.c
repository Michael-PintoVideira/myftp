/*
** EPITECH PROJECT, 2021
** MYFTP
** File description:
** le FTP
*/

#include "include.h"

char **create_double_tabs(char *clean_listen)
{
    const char s[2] = " ";
    char *to_add = strdup(clean_listen);
    int i = 0;
    char **res;

    strtok(to_add, s);
    while(strtok(NULL, s))
        i++;
    res = malloc(sizeof(char*) * (i + 1));
    res[0] = strtok(clean_listen, s);
    i = 1;
    while(res[i] = strtok(NULL, s))
        i++;
    return res;
}

char **create_double_tabs_ip(char *one_ip)
{
    const char s[2] = ".";
    char *to_add = strdup(one_ip);
    int i = 0;
    char **res;

    strtok(to_add, s);
    while(strtok(NULL, s))
        i++;
    res = malloc(sizeof(char*) * (i + 1));
    res[0] = strtok(one_ip, s);
    i = 1;
    while(res[i] = strtok(NULL, s))
        i++;
    return res;
}


void dirty_hand(char *clean_listen, the_client_t client)
{
    int len_dirty_to_listen = 1;
    char to_agrement[1];
    int place = 0;

    while(read(client.fd, to_agrement, 1) > 0){
        clean_listen[place] = to_agrement[0];
        if(to_agrement[0] == '\n')
            break;
        place++;
        len_dirty_to_listen++;
        clean_listen = realloc(clean_listen, sizeof(char) * len_dirty_to_listen);
    }
}