SRC	=	src/check.c \
		src/create_struct.c \
		src/find_path.c \
		src/get_space.c src/main.c \
    	src/my_strcmp.c \
		src/my_strcmp_custom.c \
		src/separator.c \
		src/separator_bis.c \
    	src/setenv.c \
		src/shell_command.c \
		src/start_shell.c \
		src/str_to_word_array.c

LIB	=	lib/my_flag.c \
		lib/my_printf.c \
		lib/my_putchar.c \
		lib/my_put_nbr.c \
		lib/my_putstr.c \
		lib/my_put_nbru.c \
		lib/my_putstr.c \
		lib/my_str_isalpha.c \
		lib/my_str_isnum.c \
		lib/my_strcat_bis.c \
		lib/my_strcpy.c \
		lib/my_strlen.c

MAIN	=	src/main.c

CFLAGS	=	-g -I./include

OBJ	=	$(MAIN:.c=.o) $(SRC:.c=.o) $(LIB:.c=.o)

NAME	=	minishell

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

all: $(NAME)

clean:
	rm -f $(OBJ)
	@rm -f *.gc*

fclean:	clean
	rm -f $(NAME)

re: fclean all