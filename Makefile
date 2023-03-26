NAME	=   libftprintf.a
CC 		= 	cc
SRCS	=   ft_printf.c \
			ft_printstr.c \
			ft_putstr.c\
			ft_itoa.c\
			ft_putchar.c\
			ft_printu.c\
			ft_hexademical.c \
			
OBJS	= $(SRCS:.c=.o)
RM		= rm -f
LIBC	= ar rcs
FLAGS	= -Wall -Wextra -Werror

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	${LIBC} $(NAME) $(OBJS)

all: $(NAME)
    
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
   
re: fclean all

.PHONY: all bonus clean fclean re
