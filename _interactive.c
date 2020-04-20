#include "hsh.h"
/**
 * _interactive - Creates a loop that execute command lines entered by tty
 * @av: argument from main
 * Return: Exit / Error Code
*/
int _interactive(char **av __attribute__((unused)))
{
	size_t bufsiz;
	char *buffer = NULL;
	char **env_args = NULL;
	char **user_command = NULL;
	char *full_command = NULL;
	int (*b_func)() = NULL;

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		getline(&buffer, &bufsiz, stdin);
		validagetline(buffer, 0, user_command, env_args);
		if (buffer[0] == 10 || buffer[0] == 9)
			continue;
		user_command = args_constructor(buffer);
		if (user_command == NULL)
			continue;
		b_func = find_builtins(*user_command);
		if (b_func)
		{
			if (b_func == exit_func)
				free_all(user_command, env_args, buffer, NULL);
			b_func();
			free_all(user_command, NULL, NULL, NULL);
			continue;
		}
		env_args = getenvpath();
		if (env_args == NULL)
			return (-1);
		full_command = _insert_path(user_command, env_args);
		if (full_command == NULL)
			write(STDOUT_FILENO, "command NOT found\n", 18);
		else
			execo(full_command, user_command);
		freedom(1, buffer), buffer = NULL;
		freedom(2, user_command), user_command = NULL;
		freedom(2, env_args), env_args = NULL;
	}
	return (0);
}
