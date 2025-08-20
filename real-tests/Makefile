NAME	= tester

SRCS := $(shell find . -name "*.c")


FLAGS	= -Wall -Wextra -Werror
INCL	= -I. -I../lib -I../lib/libft
LIB		= -L../lib -lunit -L../lib/libft -lft

all :	$(NAME)

${NAME} :	libunit.a
	gcc $(FLAGS) $(INCL) $(LIB) $(SRCS) -o $(NAME)
	@printf "tester done!\n"

libunit.a :
	make -C ../lib

clean :
	make fclean -C ../lib
	@rm tester
	@printf "Tester deleted\n"

fclean :	clean

bonus :		all

re :	clean all

.PHONY :	re all clean
