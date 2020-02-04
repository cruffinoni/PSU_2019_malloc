##
## EPITECH PROJECT, 2018
## makefile
## File description:
## This file is used for compilation of src and lib
##

SRC	= 		./src/malloc.c

MAIN_FILE	=
SRC_TEST	=	./tests/automated/env.c

NAME			=	malloc
NAME_TEST		=	test_mysh
INCLUDE_PATH	=	./include/

CFLAGS		=	-Wall -Wextra -I $(INCLUDE_PATH)
ALL_SRC		=	$(SRC) $(SRC_CMDS) $(PARSING)
OBJ			=	$(ALL_SRC:.c=.o)
OBJ_MAIN	=	$(MAIN_FILE:.c=.o)

$(NAME): $(OBJ) $(OBJ_MAIN)
	gcc -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CFLAGS)

all: $(NAME)

debug:
	gcc -o $(NAME) $(ALL_SRC) $(MAIN_FILE) $(CFLAGS) -g

tests_run:
	gcc -o $(NAME_TEST) $(SRC_TEST) $(ALL_SRC) $(CFLAGS) -I ./tests/ -lcriterion --coverage

clean:
	@rm -f $(OBJ) $(OBJ_MAIN) $(LIB_NAME)
	$(MAKE) -C $(LIB_PATH) clean

fclean:
	rm -f $(OBJ) $(OBJ_MAIN) $(LIB_NAME)
	@rm -f $(NAME) $(NAME_TEST)
	$(MAKE) -C $(LIB_PATH) fclean

clean_prog_obj:
	@rm -f $(OBJ)

re_ex: clean_prog_obj $(OBJ) $(OBJ_MAIN)
	@rm -f $(NAME)
	gcc -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CFLAGS)

re:		fclean all

.PHONY:	all clean fclean re debug compile_lib re_ex
