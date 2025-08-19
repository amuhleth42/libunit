#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

# include "libft.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct s_unit_test
{
	char				*name;
	int					(*test_func)();
	struct s_unit_test	*next;
}					t_unit_test;

void	load_test(t_unit_test **testlist, char *name, int (*test_func)(void));
int		launch_tests(t_unit_test **testlist);


// utils

t_unit_test *test_lstnew(char *name, int (*test_func)());
t_unit_test	*test_lstlast(t_unit_test *lst);
void		test_lstadd_back(t_unit_test **alst, t_unit_test *new);

#endif
