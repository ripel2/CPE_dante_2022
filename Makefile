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

GEN_TESTS = tests/tests_btree.c \
	tests/tests_generator.c \
	tests/tests_carve_blocks.c

SOLV_TESTS = tests/tests_load_maze.c \
	tests/tests_error_handling.c \
	tests/tests_nodeify_maze.c \
	tests/tests_queue.c \
	tests/tests_neighbors.c \
	tests/tests_print_solved_maze.c

COVERAGE_FLAGS = -fprofile-arcs -ftest-coverage --coverage

GEN_TESTS_FLAGS = $(COVERAGE_FLAGS) -Igenerator/include -lcriterion
SOLV_TESTS_FLAGS = $(COVERAGE_FLAGS) -Isolver/include -lcriterion

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

make_tests: clean
	gcc -o generator_unit_tests $(GEN_TESTS) $(GEN_SRC) $(GEN_TESTS_FLAGS)
	gcc -o solver_unit_tests $(SOLV_TESTS) $(SOLV_SRC) $(SOLV_TESTS_FLAGS)

tests_run: make_tests
	./solver_unit_tests --always-succeed
	./generator_unit_tests --always-succeed

coverage:
	gcovr . --exclude tests/
	gcovr . --exclude tests/ -b

.PHONY: all clean fclean re
