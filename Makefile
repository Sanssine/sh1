NAME=ft_minishell1

SOURCE=main.c \
read.c \
algo1.c \
env.c \
execute.c \
set.c \
unsetenv.c

POINTO=main.o \
read.o \
algo1.o \
env.o \
execute.o \
set.o \
unsetenv.o

FLAG= -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C libft/ fclean
	make -C libft/
	gcc $(FLAG) -I libft/includes -c $(SOURCE) 
	gcc $(FLAG) -I libft/includes -c main.c
	gcc -o $(NAME) $(POINTO) -L libft/ -lft

clean:
	make -C libft/ clean
	rm -rf $(POINTO)

fclean: clean
	rm -rf $(NAME)

test:
	make re
	./ft_minishell1
	make fclean

re: fclean $(NAME)

.PHONY: all $(NAME) clean fclean re test