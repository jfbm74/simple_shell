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
	struct stat *verify = malloc(sizeof(struct stat) + 1);
	int counter = 0;
	char *tmp1 = NULL;
	char *tmp2 = NULL;
	/**Verificar si el comando ya tiene incluido algun tipo de directorio, en cuyo caso salta*/
	if (_strstr(args[0], "/"))
	{
		tmp2 = args[0];
	}
	else
	{
		while (path[counter] != NULL)
		{
			chdir(path[counter]);
			if (stat(args[0], verify) == 0)
			{
				tmp1 = strduplicate(args[0]);
				tmp2 = strduplicate(path[counter]);
				/*while(tmp2[i] != '\0')
					i++;*/
				/*tmp2[i] = '/';*/
				strconk(tmp2, "/");
				strconk(tmp2, tmp1);
				break;
			}
			counter++;
		}
	}
	chdir(cwd);
	/** Si no encontró el directorio, lo retorna el comando original del usuario */
	if(tmp1 != NULL)
	{
		free(tmp1);
		tmp1 =  NULL;
	}
	free(verify);
	verify = NULL;
	free(cwd);
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
