#include <stdio.h>

/**
 * _compare - compares two strings at a given position
 * @x: string to be compared
 * @y: string to compare
 * Return: Nohing
*/
int _compare(char *x, char *y)
{
	while (*x && *y)
	{
		if (*x != *y)
			return (0);

		x++;
		y++;
	}

	return (*y == '\0');
}

/**
 * stringstring - compares two strings at a given position
 * @x: string to be compared
 * @y: string to compare
 * Return: pointer to the first occurence
*/
char *stringstring(char *x, char *y)
{
	while (*x != '\0')
	{
		if ((*x == *y) && _compare(x, y))
			return (x);
		x++;
	}

	return (NULL);
}
