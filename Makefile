NAME=bsq
SOURCES=src/main.c \
	src/str.c \
	src/utils.c \
	src/solve.c
OBJECTS=$(patsubst src/%.c, bin/%.o, $(SOURCES))

all: $(NAME)

$(NAME): bin $(OBJECTS)
	cc -O3 -Wall -Wextra -Werror -o $(NAME) $(OBJECTS)

bin:
	mkdir -p bin

bin/%.o: src/%.c
	cc -O3 -Wall -Wextra -Werror -c -o $@ $^

clean:
	rm -rf bin

fclean: clean
	rm -f $(NAME)

re: fclean all
