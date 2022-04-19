##
## EPITECH PROJECT, 2022
## dante
## File description:
## Makefile for the dante project
##

NAME = solver

MAIN = src/main.c

SRC = src/solver.c \
	src/error_message.c \
	src/destroy_maze.c \
	src/nodeify_maze.c \
	src/queue.c \
	src/neighbors.c \
	src/print_solved_maze.c \
	src/load_maze.c

WARNING_FLAGS = -Wextra -Wall -Wshadow -Werror -Wno-unused-result

CFLAGS = -Iinclude $(WARNING_FLAGS) -O3 -Ofast

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
