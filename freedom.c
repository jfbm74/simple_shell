#include "hsh.h"
/**
* freedom - free the memory double or simple pointer
* @n: 1 is Pointer, 2 is double pointer
* Return: nothing
*/

void freedom(int n, ...)
{
	int i = 0;
	char **ptr2 = NULL;
	char *ptr1 = NULL;
	va_list arg;

	va_start(arg, n);

	if (n == 1)
	{
		ptr1 = va_arg(arg, char *);
		free(ptr1);
	}

	if (n == 2)
	{
		ptr2 = va_arg(arg, char **);
		while (ptr2[i] != NULL)
		{
			free(ptr2[i]);
			i++;
		}
		free(ptr2);
	}
}

/**
* free_all - frees tokenized PATH directories and user's arguments
* @dptr1: first double pointer to free
* @dptr2: second double pointer to free
* @sptr1: first single pointer to free
* @sptr2: second double pointer to free
* Return: nothing
*/

void free_all(char **dptr1, char **dptr2, char *sptr1, char *sptr2)
{

	if (dptr1 != NULL)
	{
		freedom(2, dptr1);
		dptr1 = NULL;
	}
	if (dptr2 != NULL)
	{
		freedom(2, dptr2);
		dptr2 = NULL;
	}
	if (sptr1 != NULL)
	{
		free(sptr1);
		sptr1 = NULL;
	}
	if (sptr2 != NULL)
	{
		free(sptr2);
		sptr2 = NULL;
	}
}
