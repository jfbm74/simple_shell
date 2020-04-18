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
	char *buffer = NULL, **args = NULL, **env_args = NULL, *tmp = NULL;

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		readbuffer = getline(&buffer, &bufsiz, stdin);
		if (readbuffer == EOF)
		{
			write(STDOUT_FILENO, "\n", 1);
			if (buffer != NULL)
			{
				free(buffer);
				buffer = NULL;
			}
			
			
			if (args != NULL)
			{
				freedom(2, args);
				args =  NULL;
			}
			if (env_args != NULL)
			{
				freedom(2, env_args);
				env_args = NULL;
			}
			/*
			if (av != NULL)
			{
				freedom(2, av);
			}
			*/
			exit(0);
		}
		else
		{
			if (buffer[0] == 10 || buffer[0] == 9)
				continue;
			size = necklace_pearls(buffer);/*This size is +1 from the return*/
			args = parsing(buffer, size);
			b_func = find_builtins(*args);
			if (b_func != NULL)
			{
				if (b_func == exit_func)
				{
					if (buffer != NULL)
					{
						free(buffer);
						buffer = NULL;
					}
					if (args != NULL)
					{
						freedom(2, args);
						args =  NULL;
					}
					if (env_args != NULL)
					{
						freedom(2, env_args);
						env_args = NULL;
					}
				}
				b_func();
			}
			if (flag == 0)
			{
				env_args = getenvpath();
				flag = 1;
			}
			tmp = _insert_path(args, env_args);/*tmp is Null if is not valid*/
			if (tmp != NULL)
			{
			free(args[0]);
			args[0] = tmp;
			errcode = execo(args);
			} 
			if (buffer != NULL)
			{
				freedom(1, buffer);
				buffer = NULL;
			}
			if (args != NULL)
			{
				freedom(2, args);
				args =  NULL;
			}
			loop++;
			
		}

	}
	return (errcode);
}
