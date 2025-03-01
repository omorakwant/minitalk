CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = client server
OBJECTS = client.o server.o
PRINTF = ft_printf/
LIBFT = libft/

all: $(NAME)

server: server.o
	$(CC) $(FLAGS) server.o $(PRINTF)printf.a $(LIBFT)libft.a -o server

client: client.o
	make -C $(PRINTF)
	make -C $(LIBFT)
	$(CC) $(FLAGS) client.o $(PRINTF)printf.a $(LIBFT)libft.a -o client

clean:
	make clean -C $(PRINTF)
	make clean -C $(LIBFT)
	rm -f *.o

fclean: clean
	make fclean -C $(PRINTF)
	make fclean -C $(LIBFT)
	rm -rf $(NAME)
	
re : fclean all

.SECONDARY: $(OBJECTS)

.PHONY: all clean fclean