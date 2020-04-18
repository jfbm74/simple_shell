#include "hsh.h"

/**
 * ret_path_line - Finds the PATH variable from enviroment
 * Return: pointer position of the PATH variable
*/
char *ret_path_line()
{
	int i = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strcomparer(environ[i], "PATH") == 0)
			break;
	}
	return (environ[i]);
}

/**
 * change_equal_sig - Change from a given strings = to : character
 * @str: given string
 * Return: Nohing
*/
void change_equal_sig(char *str)
{
	char **ptr_str = NULL;
	int i = 0;

	ptr_str = &str;

	while (ptr_str[0][i] != '=')
	{
		ptr_str[0][i] = ':';
		i++;
	}
	ptr_str[0][i] = ':';
}

/**
 * _insert_path - Inserts the directory into given command
 * @args: given command
 * @path: tokenized path enviroment
 * Return: Full path command if exists or just a given command
*/

char *_insert_path(char **args, char **path)
{
	char *cwd = getcwd(NULL, 0);
	struct stat verify;
	int counter = 0;
	char *tmp2 = NULL;

	if (_strstr(args[0], "/"))
	{
		tmp2 = args[0];
	}
	else
	{
		while (path[counter] != NULL)
		{
			tmp2 = malloc(sizeof(char *) * (strlen(path[counter]) + 1 + strlen(args[0])));
			if (tmp2 == NULL)
			{
				freedom(1, tmp2);
			}
			
			chdir(path[counter]);
			if (stat(args[0], &verify) == 0)
			{
				strcpy(tmp2, path[counter]);
				strcat(tmp2, "/");
				strcat(tmp2, args[0]);
				break;
			}
			counter++;
		}
	}
	chdir(cwd);
	printf("%s\n", tmp2);
	sleep(3);
	if (tmp2 == NULL)
	{
		freedom(1, cwd);
		cwd = NULL;
		freedom(1, tmp2);
		tmp2 = NULL;
		return (args[0]);
	}

	freedom(1, cwd);
	cwd = NULL;
	return (tmp2);
}

/**
 * getenvpath - Creates an array of pointers to the PATH directories
 * Return: Pointer to an array of tokenized directories
*/
char **getenvpath()
{
	char *tmp = NULL;
	int size_args = 0;
	char **env_args = NULL;

	tmp = ret_path_line();
	change_equal_sig(tmp); /*Change  PATH= for PATH:*/
	size_args = necklace_pearls(tmp);
	env_args = parsing(tmp, size_args);
	tmp =  NULL;
	return (env_args);
}
