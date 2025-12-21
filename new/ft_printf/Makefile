NAME = libftprintf.a

SRCS = ft_printf.c \
		ft_utils.c

OBJS = $(SRCS:.c=.o)

HEADER = ft_printf.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -rf

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
