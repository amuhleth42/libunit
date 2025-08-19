#include <unistd.h>
#include "libft.h"

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
