#include "hsh.h"
/**
 * non_interactive_mode - executes command lines entered by pipe
 * @av: program name
 * Return: 0
*/
int non_interactive_mode(char **av __attribute__((unused)))
{
	char *buffer = NULL;
	char *full_command = NULL;
	int size, len, flag = 0;
	size_t bufsiz;
	char **args = NULL;
	char **env_args = NULL;
	int (*b_func)() = NULL;

	while ((len = getline(&buffer, &bufsiz, stdin)) > 0)
	{
		if (len == EOF)
		{
			write(STDOUT_FILENO, "\n", 1);
			free_all(args, env_args, buffer, NULL);
			exit(0);
		}
		else
		{
			if (buffer[0] == 10 || buffer[0] == 9)
				continue;
			size = necklace_pearls(buffer);
			args = parsing(buffer, size);
			b_func = find_builtins(*args);
			if (b_func != NULL)
			{
				if (b_func == exit_func)
					free_all(args, env_args, buffer, NULL);
				b_func();
				free_all(args, NULL, buffer, NULL);
				continue;
			}
			if (flag == 0)
			{
				env_args = getenvpath();
				flag = 1;
			}

			if (args[0] == NULL)
				continue;
			full_command = _insert_path(args, env_args);
			if (full_command == NULL)
			{
				write(STDOUT_FILENO, "command not found\n", 18);
				freedom(1, buffer);
				buffer = NULL;
				freedom(2, args);
				args = NULL;
				loop++;
				continue;
			}
			else
				errcode = execo(full_command, args);
			loop++;
			freedom(1, buffer);
			buffer = NULL;
			freedom(2, args);
			args = NULL;
			full_command = NULL;
		}
	}
	freedom(1, buffer);
	buffer = NULL;
	freedom(2, env_args);
	env_args = NULL;
	return (0);
}
