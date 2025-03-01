CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = printf.a
SRCS = ft_putchar.c ft_putstr.c ft_putnbr.c ft_printf.c\
		ft_puthexa.c ft_putptr.c
OFILES = $(SRCS:.c=.o)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

all: $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SECONDARY : $(OFILES)