# Variables
CLIENT = client
SERVER = server
NAME = client server
NAME_BONUS = client_bonus server_bonus



CLIENT_SRC = minitalk_srcs/client/client.c
SERVER_SRC = minitalk_srcs/server/server.c
CLIENT_BONUS_SRC = minitalk_srcs/client/client_bonus.c
SERVER_BONUS_SRC = minitalk_srcs/server/server_bonus.c

UTILS_SRC = minitalk_srcs/utils/mini_utils.c
UTILS_BONUS_SRC = minitalk_srcs/utils/mini_utils_bonus.c

CLIENT_OBJS = $(CLIENT_SRC:.c=.o)
SERVER_OBJS = $(SERVER_SRC:.c=.o)
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRC:.c=.o)
SERVER_BONUS_OBJS = $(SERVER_BONUS_SRC:.c=.o)
UTILS_OBJS = $(UTILS_SRC:.c=.o)
UTILS_BONUS_OBJS = $(UTILS_BONUS_SRC:.c=.o)

HEADER_DIR = minitalk_headers
LIBFT = libft/libft.a

# Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I $(HEADER_DIR)

# Rules
all: $(NAME)

bonus: $(NAME_BONUS)

client: $(CLIENT_OBJS) $(UTILS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(UTILS_OBJS) $(LIBFT) -o client

server: $(SERVER_OBJS) $(UTILS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(UTILS_OBJS) $(LIBFT) -o server

client_bonus: $(CLIENT_BONUS_OBJS) $(UTILS_BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) $(UTILS_BONUS_OBJS) $(LIBFT) -o client_bonus

server_bonus: $(SERVER_BONUS_OBJS) $(UTILS_BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJS) $(UTILS_BONUS_OBJS) $(LIBFT) -o server_bonus

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT):
	@echo "Compiling Libft..."
	@make -C ./libft

clean:
	@echo "Cleaning object files..."
	@rm -f $(CLIENT_OBJS) $(SERVER_OBJS) $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS) $(UTILS_OBJS) $(UTILS_BONUS_OBJS)
	@make -C ./libft clean

fclean: clean
	@echo "Cleaning binaries..."
	@rm -f $(NAME) $(NAME_BONUS)
	@make -C ./libft fclean

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus
