#include "hsh.h"
/**
 * _interactive - Creates a loop that execute command lines entered by tty
 * @av: argument from main
 * Return: Exit / Error Code
*/
int _interactive(char **av __attribute__((unused)))
{
	int size = 0;
	int flag = 0;
	int  readbuffer = 0;
	int (*b_func)() = NULL;
	size_t bufsiz;
	char *buffer = NULL, **args = NULL, **env_args = NULL;

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		readbuffer = getline(&buffer, &bufsiz, stdin);
		if (readbuffer == EOF)
		{
			write(STDOUT_FILENO, "\n", 1);
			free(buffer);
			freedom(2, args);
			freedom(2, env_args);
			/*freedom(2, av);*/
			exit (0);
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
					free_env(env_args, args);
				b_func();
			}
			
			if (flag == 0)
			{
				env_args = getenvpath();
				flag = 1;
			}
			args[0] = _insert_path(args, env_args);

			errcode = execo(args);
			
			loop++;
		}

	}
	return (errcode);
}
