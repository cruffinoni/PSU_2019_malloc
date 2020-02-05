##
## EPITECH PROJECT, 2019
## makefile
## File description:
## This file is used for compilation of src and lib
##

SRC	= 		./src/malloc.c	\
			./src/binary_tree.c	 \
			./src/binary_add.c

SRC_TEST	=	./tests/simple.c

NAME			=	malloc
NAME_TEST		=	test_malloc
INCLUDE_PATH	=	./include/
FORCE_TEST		=	force_test

CFLAGS		=	-Wall -Wextra -I $(INCLUDE_PATH)
OBJ			=	$(SRC:.c=.o)
LIB_NAME	=	lib_malloc.so

all:
	gcc -shared -o $(LIB_NAME) -fPIC $(SRC) $(CFLAGS)

debug:
	gcc -o $(NAME) $(SRC) $(MAIN_FILE) $(CFLAGS) -g

tests_run: all
	gcc -o $(NAME_TEST) $(SRC_TEST) $(CFLAGS) -I ./tests/

force_tests:
	gcc $(SRC) $(SRC_TEST) $(CFLAGS) -o $(FORCE_TEST)  -g

clean:
	@rm -f $(OBJ) $(LIB_NAME)

fclean:
	rm -f $(OBJ) $(LIB_NAME)
	rm -f $(FORCE_TEST) $(LIB_NAME)
	@rm -f $(NAME) $(NAME_TEST)

clean_prog_obj:
	@rm -f $(OBJ)

re_ex: clean_prog_obj $(OBJ)
	@rm -f $(NAME)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

re:		fclean all

.PHONY:	all clean fclean re debug compile_lib re_ex force_tests
