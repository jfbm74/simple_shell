#include "hsh.h"
/**
* free_env - frees tokenized PATH directories and user's arguments
* @env_args: tokenized environment directories
* @args: tokenized user's commands
* Return: nothing
*/

void free_env(char **env_args, char **args)
{
	if (env_args != NULL)
	{
		freedom(2, env_args);
	}
	freedom(2, args);
}
