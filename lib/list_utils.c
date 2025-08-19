#include "libunit.h"

t_unit_test	*test_lstnew(char *name, int (*test_func)())
{
	t_unit_test	*new;

	new = (t_unit_test *) ft_calloc(sizeof(t_unit_test), 1);
	if (!new)
		return (NULL);
	new->name = name;
	new->test_func = test_func;
	return (new);
}

t_unit_test	*test_lstlast(t_unit_test *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	test_lstadd_back(t_unit_test **alst, t_unit_test *new)
{
	t_unit_test *last;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	last = test_lstlast(*alst);
	last->next = new;
}
