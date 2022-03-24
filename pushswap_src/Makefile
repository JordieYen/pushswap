NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

LIB = -Llibft -lft

INCLUDES = -Iincludes

MAIN = push_swap.c 

SRC =	errorchecks.c \
		instructions_utils.c \
		sort100.c \
		sort5.c \
		sort_utils.c \
		sort_utils_3.c \
		stack_checkers.c \
		instructions.c \
		sort3.c \
		sort500.c \
		sort_utils_2.c \
		sort_utils_4.c \
		frees.c \
		sort4and2.c \
		sortunder10.c

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): ${OBJ}
	make re -C libft
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ ${MAIN} ${OBJ} $(LIB)
	make clean
	make clean -C libft

clean:
	@$(RM) $(OBJ)
	make clean -C libft

fclean: clean
	@$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: clean fclean
