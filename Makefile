#Variables
NAME = client server
NAME_BONUS = client_bonus server_bonus
CLIENT_DIR = ./minitalk_srcs/client/client.c
SERVER_DIR = ./minitalk_srcs/server/server.c
CLIENT_BONUS_DIR = ./minitalk_srcs/client_bonus/client_bonus.c
SERVER_BONUS_DIR = ./minitalk_srcs/server_bonus/server_bonus.c

HEADER_DIR = ./minitalk_headers/minitalk.h
HEADER_BONUS_DIR = ./minitalk_headers/minitalki_bonus.h
LIBFT_DIR = ./libft/libft.a

#Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I $(HEADER_DIR)
IFLAGS_BONUS = -I $(HEADER_BONUS_DIR)

#Rules
libft:
	echo "COMPILING THE LIBFT..."
	cd libft/ && make

cc_client:
	$(CC) $(CFLAGS) $(IFLAGS) $(CLIENT_DIR) $(LIBFT_DIR) -o client

cc_server:
	$(CC) $(CFLAGS) $(IFLAGS) $(SERVER_DIR) $(LIBFT_DIR) -o server

cc_client_bonus:
	$(CC) $(CFLAGS) $(IFLAGS_BONUS) $(CLIENT_BONUS_DIR) $(LIBFT_DIR) -o client_bonus

cc_server_bonus:
	$(CC) $(CFLAGS) $(IFLAGS_BONUS) $(SERVER_BONUS_DIR) $(LIBFT_DIR) -o server_bonus


all: libft cc_client cc_server

bonus: libft cc_client_bonus cc_server_bonus

clean: cd libft/ && make clean

fclean: $(RM) $(NAME) $(NAME_BONUS)
	cd libft/ && make fclean

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus
