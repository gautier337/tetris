##
## EPITECH PROJECT, 2022
## Makefile for Tetris
## File description:
## Xavier VINCENT - Gautier BONHUR
##

NAME            =   		tetris
TEST_NAME       =			unit_tests

SRC_MAIN        =   		$(addprefix src/, \
							main.c)

SRC             =   		$(addprefix src/, \
							debug/debug_mode.c \
							debug/functions_file_tetriminos.c \
							errors/check_same_keys.c \
							errors/check_tetrimino.c \
							errors/help.c \
							event/check_event.c \
							event/reset_moving.c \
							event/check_movement_sides.c \
							free/free_all.c \
							init/data.c \
							init/key_bindings.c \
							init/load_map.c \
							init/map_size.c \
							init/options.c \
							init/struct.c \
							init/tetriminos.c \
							tools/create_tetriminos.c \
							tools/data.c \
							tools/draw_tetriminos.c \
							tools/draw_windows.c \
							tools/get_time.c \
							tools/my_tetris_getnbr.c \
							tools/windows.c \
							display_game.c \
							tetris.c)

SRC_TESTS       =   		$(addprefix tests/, \
							)
SRC_TESTS       +=  		$(SRC)

override CC     =   		gcc
override RM     =   		rm -rf

OBJ_MAIN        =   		$(SRC_MAIN:.c=.o)
OBJ             =   		$(SRC:.c=.o)

CFLAGS          +=  		-Iinclude -W -Wall -Wextra
LDFLAGS         =   		-Llib -lmy -lncurses
CRITERION       =   		--coverage -lcriterion

COMPILING_LIBS  =   		"*******  COMPILING LIBS.  *******"
LIBS_COMPILED   =   		"*******   LIBS COMPILED   *******"
COMPILING_SRCS  =   		"*******  COMPILING SRCS.  *******"
SRCS_COMPILED   =   		"*******   SRCS COMPILED   *******"
COMPILING_TESTS =   		"*******  COMPILING TESTS  *******"
TESTS_COMPILED  =   		"*******  TESTS COMPILED.  *******"
CLEANING        =   		"*******     CLEANING.     *******"
CLEANED         =   		"*******  CLEAN COMPLETED  *******"
TESTING         =   		"*******      TESTING.     *******"
TESTED          =   		"*******  TESTS FINISHED.  *******"

all:            $(NAME)

$(NAME):        $(OBJ_MAIN) $(OBJ)
	@echo ""
	@echo $(COMPILING_LIBS)
	make -C lib re
	@echo $(LIBS_COMPILED)
	@echo ""
	@echo $(COMPILING_SRCS)
	@echo cc "\t" -o $(OBJ_MAIN)
	@echo cc "\t" -o $(OBJ)
	@$(CC) -o $(NAME) $(OBJ_MAIN) $(OBJ) $(CFLAGS) $(LDFLAGS)
	@echo $(SRCS_COMPILED)
	@echo ""

clean:
	@echo ""
	@echo $(CLEANING)
	$(RM) $(OBJ_MAIN)
	$(RM) $(OBJ)
	$(RM) *.gcda
	$(RM) *.gcno
	@make -C lib clean
	@echo $(CLEANED)
	@echo ""

fclean:			clean
	$(RM) $(NAME)
	@make -C lib fclean

re:			clean all

tests_run:
	@echo ""
	@echo $(COMPILING_LIBS)
	make -C lib re
	@echo $(LIBS_COMPILED)
	@echo ""
	@echo $(COMPILING_TESTS)
	$(CC) -o $(TEST_NAME) $(SRC_TESTS) $(CFLAGS) $(LDFLAGS) $(CRITERION)
	@echo $(TESTS_COMPILED)
	@echo ""
	@echo $(TESTING)
	./$(TEST_NAME)
	$(RM) $(TEST_NAME)
	@echo $(TESTED)
	@echo ""

cover:
	gcovr --exclude tests/
	gcovr --branches --exclude tests/

my_tests: 		tests_run cover fclean

.PHONY: 		all $(NAME) clean fclean re tests_run cover my_tests
