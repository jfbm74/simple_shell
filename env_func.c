#include "hsh.h"
/**
 * env_func - Prints eviroment variables
 * Return: 0 on success
*/
int env_func(void)
{
	int counter = 0, lenght = 0;

	while (environ[counter] != NULL)
	{
		lenght = strlarge(environ[counter]);
		write(STDOUT_FILENO, environ[counter], lenght);
		write(STDOUT_FILENO, "\n", 1);
		counter++;
	}
	/*write(STDOUT_FILENO, "\n", 1);*/
	return (0);
}
