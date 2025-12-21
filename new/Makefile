SRCS_SERVER = src/server.c
SRCS_CLIENT = src/client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

LIBFT_PRINTF = ft_printf/libftprintf.a

all: server client

$(LIBFT_PRINTF):
	make -C ft_printf

server: $(OBJS_SERVER) $(LIBFT_PRINTF)
	$(CC) -o $@ $(OBJS_SERVER) $(LIBFT_PRINTF)

client: $(OBJS_CLIENT) $(LIBFT_PRINTF)
	$(CC) -o $@ $(OBJS_CLIENT) $(LIBFT_PRINTF)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	make -C ft_printf clean

fclean: clean
	rm -f server client
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
