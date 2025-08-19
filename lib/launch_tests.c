#include "libunit.h"

void	error_exit(char *s)
{
	ft_putstr_fd("libunit: ", STDERR);
	perror(s);
	exit(EXIT_FAILURE);
}
int run_test(t_unit_test *test)
{
	int	pid;
	int	status;
	int code;

	pid = fork();
	if (pid < 0)
		error_exit("fork");
	else if (pid == 0)
		exit(test->test_func());
	else
	{
		waitpid(pid, &status, 0);
		if (WIFSIGNALED(status))
        {
            code = WTERMSIG(status);
            if (code == SIGSEGV)
                ft_printf("%s:SIGSEGV\n", test->name);
            else if (code == SIGBUS)
                ft_printf("%s:SIGBUS\n", test->name);
            else
                ft_printf("%s:Signal %d\n", test->name, code);
            return (-1);
        }
		code = WEXITSTATUS(status);
		if (code == 0)
			ft_printf("%s:OK\n", test->name);
		else
			ft_printf("%s:KO\n", test->name);
		return code;
	}
	return (-1);
}

int	launch_tests(t_unit_test **testlist)
{
	t_unit_test	*lst;
	int 		result;

	if (!*testlist)
		return (0);
	lst = *testlist;
	while (lst != NULL)
	{
		result = run_test(lst) || result;
		lst = lst->next;
	}
	return (result);
}
