CFILES = main.c maze.c
OFILES = $(CFILES:.c=.o)

INCLUDES = -I ./ -I ../libGrid
LIBRARIES = -lGrid -L ../libGrid

NAME = theseRunner.exe

all: $(NAME)

$(NAME): $(OFILES)
	gcc -g -o $@  $(OFILES) $(INCLUDES) $(LIBRARIES)

%.o: %.c
	gcc -g -o $@ -c $< $(INCLUDES) $(LIBRARIES)

clean:
	rm $(OFILES) $(NAME) || true

re: clean all