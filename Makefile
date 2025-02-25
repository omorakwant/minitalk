CC = cc
FLAGS = -Wall -Wextra -Werror
TARGETS = client server
OBJECTS = client.o server.o

all: $(TARGETS)

server: server.o
	$(CC) $(FLAGS) server.o -o server

client: client.o
	$(CC) $(FLAGS) client.o -o client

clean:
	rm -f *.o

fclean: clean
	rm -rf $(TARGETS)

.SECONDARY: $(OBJECTS)

.PHONY: all clean fclean