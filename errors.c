#include "hsh.h"
/**
 * error_msg - writes error depending on the error number
 * @args: given command to execute
 * Return: Nothing
*/
void error_msg(char **args)
{
	char *error_message = malloc(sizeof(char) * 255);
	char *looper = NULL;

	looper = int_to_charac(loop);
	error_message = strduplicate(hsh_home);
	error_message = strconk(error_message, ": ");
	error_message = strconk(error_message, looper);
	error_message = strconk(error_message, ": ");
	error_message = strconk(error_message, args[0]);
	perror(error_message);
	free(error_message);
}
