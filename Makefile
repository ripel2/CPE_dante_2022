##
## EPITECH PROJECT, 2022
## dante
## File description:
## Makefile for the dante project
##

GEN_SRC = generator/src/generator.c \
	generator/src/init_btree.c \
	generator/src/last_lines.c \
	generator/src/carve_blocks.c

SOLV_SRC = solver/src/solver.c \
	solver/src/error_message.c \
	solver/src/destroy_maze.c \
	solver/src/nodeify_maze.c \
	solver/src/queue.c \
	solver/src/neighbors.c \
	solver/src/load_maze.c \
	solver/src/print_solved_maze.c

all:
	$(MAKE) -C generator/
	$(MAKE) -C solver/

clean:
	find . -name "*~" -delete -or -name "#*#" -delete
	find . -name "*.o" -delete
	find . -name "*.gcda" -delete -or -name "*.gcno" -delete

fclean: clean
	@(cd generator/ ; make fclean)
	@(cd solver/ ; make fclean)

re: fclean all

.PHONY: all clean fclean re
