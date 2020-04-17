#include "hsh.h"
/**
 * execo - Executes a given command
 * @args: Given command
 * Return: Exit = 0 or Error Number
*/
int execo(char **args)
{
	int status;
	pid_t pid;
	pid = fork();
	if (!pid)
	{
		if (execve(args[0], args, environ) == -1)
		{
			int errcode = errno;

			error_msg(args);
			exit(errcode);
		}
	}
	else
		wait(&status);
	errcode = 0;
	return (errcode);
}
