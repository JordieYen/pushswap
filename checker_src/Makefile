NAME = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

GNL = -Lgnl -l_get_next_line

LIB = -Llibft -lft

INCLUDES = -Iincludes

MAIN = checker.c 

SRC =	instructions.c \
		instructions_utils.c \
		frees.c \
		execute_instructions.c \
		errorchecks.c

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): ${OBJ}
	make re -C libft
	make re -C gnl
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ ${MAIN} ${OBJ} $(LIB) $(GNL)
	make clean

clean:
	@$(RM) $(OBJ)
	make clean -C libft
	make clean -C gnl

fclean: clean
	@$(RM) $(NAME)
	make fclean -C libft
	make fclean -C gnl

re: fclean all

.PHONY: clean fclean
