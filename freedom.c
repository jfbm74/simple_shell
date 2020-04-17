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
