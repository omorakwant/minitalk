CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = client server
OBJECTS = client.o server.o
BONUS = client_bonus server_bonus
BONUS_OBJ = client_bonus.o server_bonus.o
PRINTF = ft_printf/
LIBFT = libft/

PRINTFA = ft_printf/printf.a
LIBFTA = libft/libft.a

all: $(LIBFTA) $(PRINTFA) $(NAME)

$(LIBFTA):
	make -C $(LIBFT)
$(PRINTFA):
	make -C $(PRINTF)

bonus: $(LIBFTA) $(PRINTFA) $(BONUS)
	
server_bonus: server_bonus.o
	$(CC) $(FLAGS) server_bonus.o $(PRINTF)printf.a $(LIBFT)libft.a -o server_bonus

client_bonus: client_bonus.o
	$(CC) $(FLAGS) client_bonus.o $(PRINTF)printf.a $(LIBFT)libft.a -o client_bonus

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
	rm -rf $(NAME) $(BONUS)
	
re : fclean all

.SECONDARY: $(OBJECTS) $(BONUS_OBJ)

.PHONY: all clean fclean