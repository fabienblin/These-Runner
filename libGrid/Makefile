CFILES = libGrid.c
OFILES = $(CFILES:.c=.o)

INCLUDES = -I ./
NAME = libGrid.a

all: $(NAME)

$(NAME): $(OFILES)
	ar rc -o $(NAME) $(OFILES)

%.o: %.c
	gcc -c $< -o $@ $(INCLUDES)

clean:
	rm $(OFILES) $(NAME) || true

re: clean all