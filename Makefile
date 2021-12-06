SRC = ft_printf.c ft_calloc.c  ft_putnbr.c ft_putchar.c ft_puthexa.c ft_putnbnr2.c ft_putstr.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)

.c.o:
	cc -Wall -Werror -Wextra -c $(SRC)
	ar -rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ) 

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean all

.PHONY : re all fclean clean
