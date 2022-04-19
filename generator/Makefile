##
## EPITECH PROJECT, 2022
## dante
## File description:
## Makefile for the dante project
##

NAME = generator

MAIN = src/main.c

SRC = src/generator.c \
	src/init_btree.c \
	src/last_lines.c \
	src/carve_blocks.c

WARNING_FLAGS = -Wextra -Wall -Wshadow -Werror

CFLAGS = -Iinclude $(WARNING_FLAGS)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) -o $(NAME) $(MAIN) $(SRC) $(CFLAGS)

clean:
	find . -name "*~" -delete -or -name "#*#" -delete
	find . -name "*.gcda" -delete -or -name "*.gcno" -delete
	find . -name "*.o" -delete -or -name "*.a" -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all build fclean re
