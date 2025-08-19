#include "libunit.h"

void	load_test(t_unit_test **testlist, char *name, int (*test_func)(void))
{
	test_lstadd_back(testlist, test_lstnew(name, test_func));
}
