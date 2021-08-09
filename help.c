/*
** EPITECH PROJECT, 2021
** MYFTP
** File description:
** le ftp
*/

#include "include.h"

void help_option(char **double_tab, char *clean_listen, \
soc_t *socket_server, the_client_t *client)
{
    if (strcmp("HELP\n", double_tab[0]) == 0 || \
    strcmp("HELP", double_tab[0]) == 0){
        switch(client->log){
            case 0:
                dprintf(client->fd, \
                "530 Please login with USER and PASS.\n");
                break;
            case 1:
                dprintf(client->fd, \
                "214-The following commands are recognized.\n");
                dprintf(client->fd, \
                " ABOR ACCT ALLO APPE CDUP CWD  DELE EPRT EPSV \
FEAT HELP LIST MDTM MKD\n");
                dprintf(client->fd, \
                " MODE NLST NOOP OPTS PASS PASV PORT PWD  \
QUIT REIN REST RETR RMD  RNFR\n");
                dprintf(client->fd, \
                " RNTO SITE SIZE SMNT STAT STOR STOU STRU SYST \
TYPE USER XCUP XCWD XMKD\n");
                dprintf(client->fd, " XPWD XRMD\n");
                dprintf(client->fd, "214 Help OK.\n");
                break;
        }
    }
}

void print_the_help(void)
{
    printf("USAGE: ./server port path\n\tport\tis the port number");
    printf(" on which the server socket listens\n\tpath\tis the ");
    printf("path to the home directory for the Anonymous user\n");
}