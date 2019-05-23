CC = g++
FLAGS = -Wall -Wextra
LINKS = -lsfml-graphics -lsfml-system -lsfml-window
OBJS = click.o

default: build

click.o: click.cc
	$(CC) $(FLAGS) -c click.cc $(LINKS)

build: $(OBJS)
	$(CC) $(FLAGS) -o click $(OBJS) $(LINKS)

clean:
	rm *.o click