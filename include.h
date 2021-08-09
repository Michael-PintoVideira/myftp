/*
** EPITECH PROJECT, 2021
** MYFTP
** File description:
** le ftp
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>

typedef struct soc_s
{
    int port_int;
    int socket_p;
    char *the_path;
    struct sockaddr_in server_address;
    struct protoent *the_protocole;
    socklen_t taille;
    int client_socket;
    fd_set current_sockets;
    fd_set ready_sockets;
    char *first_ip;
}soc_t;

typedef struct the_client{
    int fd;
    char *usrnm;
    char *psswrd;
    int fd_md;
    int pass_port;
    int pass_mod;
    char *ip;
    int log;
    char *full_path;
    int quit;
} the_client_t;

void print_the_help();
void dirty_hand(char *clean_listen, the_client_t client);
void user_option(char **double_tab, \
char *clean_listen, soc_t *socket_server, the_client_t *client);
void pass_option(char **double_tab, \
char *clean_listen, soc_t *socket_server, the_client_t *client);
void help_option(char **double_tab, \
char *clean_listen, soc_t *socket_server, the_client_t *client);
void pasv_option(char **double_tab, \
char *clean_listen, soc_t *socket_server, the_client_t *client);
void pwd_option(char **double_tab, \
char *clean_listen, soc_t *socket_server, the_client_t *client);
void quit_option(char **double_tab, \
char *clean_listen, soc_t *socket_server, the_client_t *client);
void noop_option(char **double_tab, \
char *clean_listen, soc_t *socket_server, the_client_t *client);
void hub_function(char *clean_listen, \
soc_t *socket_server, the_client_t *client);
char **create_double_tabs(char *clean_listen);
int define_the_serv(char **argv, soc_t *socket_server);
void init_client(the_client_t *client, soc_t *socket_server, struct sockaddr_in el_client_bg);
char **create_double_tabs_ip(char *one_ip);
char **create_double_tabs(char *clean_listen);
