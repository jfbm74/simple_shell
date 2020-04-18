#include "hsh.h"
/**
 * execo - Executes a given command
 * @args: Given command
 * Return: Exit = 0 or Error Number
*/
int execo(char *command, char **args)
{
	int status;
	pid_t pid;

	pid = fork();
	if (!pid)
	{
		if (execve(command, args, environ) == -1)
		{
			int errcode = errno;
			freedom(1, command);
			command = NULL;
			error_msg(args);
			exit(errcode);
		}
	}
	else
		wait(&status);
	errcode = 0;
	freedom(1, command);
	command = NULL;
	return (errcode);
}
