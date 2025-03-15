CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = client server
OBJECTS = client.o server.o
PRINTF = ft_printf/
LIBFT = libft/

PRINTFA = ft_printf/printf.a
LIBFTA = libft/libft.a

all: $(LIBFTA) $(PRINTFA) $(NAME)

$(LIBFTA):
	make -C $(LIBFT)
$(PRINTFA):
	make -C $(PRINTF)

server: server.o
	$(CC) $(FLAGS) server.o $(PRINTF)printf.a $(LIBFT)libft.a -o server

client: client.o
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