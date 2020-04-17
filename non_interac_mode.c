#include "hsh.h"
/**
 * non_interactive_mode - executes command lines entered by pipe
 * @av: program name
 * Return: 0
*/
int non_interactive_mode(char **av __attribute__((unused)))
{
	char *buffer = NULL;
	size_t bufsiz;
	char **args = NULL;
	int size;
	int len = 0;
	char **env_args = NULL;
	int flag = 0;

	while ((len = getline(&buffer, &bufsiz, stdin)) > 0)
	{
		if (buffer[0] == 10 || buffer[0] == 9)
			continue;
		size = necklace_pearls(buffer);
		args = parsing(buffer, size);

		if (strcomparer(args[0], "exit") == 0)
			exit(0);
		if (flag == 0)
		{
			env_args = getenvpath();
			flag = 1;
		}
		args[0] = _insert_path(args, env_args);
		execo(args);
		loop++;
	}
	return (0);
}
