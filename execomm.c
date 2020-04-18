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

	printf("comm on parent = %s\n", command);
	pid = fork();
	if (!pid)
	{
		if (execve(command, args, environ) == -1)
		{
			printf("comm on error = %s\n", command);
			int errcode = errno;
			freedom(1, command);
			command = NULL;
			error_msg(args);
			exit(errcode);
		}
		else
		{
			printf("comm on success = %s\n", command);
			freedom(1, command);
			command = NULL;
			exit(errcode);
		}
		
	}
	else
		wait(&status);

	freedom(1, command);
	command = NULL;
	
	errcode = 0;
	return (errcode);
}
