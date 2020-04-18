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
	char *full_command = NULL;

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
				if (buffer != NULL)
				{
					freedom(1, buffer);
					buffer = NULL;
				}

				if (args != NULL)
				{
					freedom(2, args);
					args = NULL;
				}
				continue;
			}
			if (flag == 0)
			{
				env_args = getenvpath();
				flag = 1;
			}

			/* free a args**/
			full_command = _insert_path(args, env_args);
			if (full_command == NULL)
			{
				printf("(%s) COMMAND NOT FOUND\n", args[0]);
				if (buffer != NULL)
				{
					freedom(1, buffer);
					buffer = NULL;
				}

				if (args != NULL)
				{
					freedom(2, args);
					args = NULL;
				}
				loop++;
				continue;
			}
			else
			{

				errcode = execo(full_command, args);
			}
			loop++;
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
			
		}

	}
	return (errcode);
}
