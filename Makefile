##
## EPITECH PROJECT, 2021
## MALLOC
## File description:
## le Malloc
##

NAME    =       myftp

CFLAGS  =       -fPIC

SRC     =       main.c \
				theline.c \
				user_option.c \
				password_options.c \
				help.c \
				pwd.c \
				quit.c \
				hub_function.c \
				init_serv_client.c \
				pasv_function.c

OBJ     =       $(SRC:.c=.o)

$(NAME) :		$(OBJ)
				gcc $(OBJ) -o $(NAME)

all     :       $(NAME)

clean   :
				rm -f $(OBJ)

fclean  :       clean
				rm -f $(NAME)

re      : fclean all
