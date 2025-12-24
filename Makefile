# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnovais <jnovais@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/20 21:38:52 by jnovais           #+#    #+#              #
#    Updated: 2025/12/20 21:38:52 by jnovais          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

INC_DIR = include
SRC_DIR = src
LIBFT_DIR = libft

INCLUDES = -I$(INC_DIR)
LIBFT    = $(LIBFT_DIR)/libft.a

SERVER  = server
CLIENT  = client

SERVER_SRC = $(SRC_DIR)/server.c
CLIENT_SRC = $(SRC_DIR)/client.c

all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(SERVER): $(SERVER_SRC)
	$(CC) $(CFLAGS) $(INCLUDES) $(SERVER_SRC) $(LIBFT) -o $(SERVER)

$(CLIENT): $(CLIENT_SRC)
	$(CC) $(CFLAGS) $(INCLUDES) $(CLIENT_SRC) $(LIBFT) -o $(CLIENT)

clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
