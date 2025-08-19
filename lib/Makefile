NAME	= libunit.a

CFLAGS	= -Wall -Werror -Wextra

INCL	= -I . -I./libft

SRCS	+=	list_utils.c			\
			load_test.c

OBJS	= ${SRCS:.c=.o}

CC		= gcc -Wall -Wextra -Werror

all:	${NAME}

${NAME}:	libft.a ${OBJS}
	@printf "\nLibft Objects done\n"
	@ar -rcs $@ ${OBJS}
	@printf "Libunit done :]\n"

libft.a:
	make -C ./libft

.c.o:
	@${CC} ${INCL} -c $< -o ${<:.c=.o}
	@printf "Libunit object : %-33.33s\r" $<

clean:
	@rm -f ${OBJS}
	make fclean -C ./libft
	@printf "libunit objects deleted\n"

fclean:	clean
	@rm -f ${NAME}
	@printf "libunit.a deleted\n"

re:	fclean all

.PHONY:		all clean fclean re 
