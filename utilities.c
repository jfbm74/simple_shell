#include "hsh.h"

/**
 * strncomparer - Compares two strings with n size
 * @s1: Given String 1
 * @s2: Given String 2
 * @n: Size to character compare
 * Return: 0 both strings are equals
*/
int strncomparer(char *s1,  char *s2, size_t n)
{
	while (n && *s1 && (*s1 == *s2))
	{
		++s1;
		++s2;
		--n;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}
}

/**
 * strlarge - Funtion that returns length of a given string
 * @s: Given string
 * Return: number of elements
*/
int strlarge(char *s)
{
	int len;

	for (len = 0; s[len] != '\0'; len++)
		;
	return (len);
}

/**
 * strduplicate - Duplicates a given string
 * @s: given string
 * Return: Copy of given string
*/
char *strduplicate(char *s)
{
	char *ptr;
	int i, len;

	len = 0;
	if (s == NULL)
		return (NULL);
	len = strlarge(s);
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		ptr[i] = s[i];
	ptr[i] = '\0';
	return (ptr);
}

/**
 * strcomparer - Compares two given  strings
 * @s1: Given S1 String
 * @s2: Given S2 String
 * Return: 0 if both are equals or ascii diff
*/
int strcomparer(char *s1, char *s2)
{
	int diff, index;

	diff = index = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[index] != '\0' && s2[index] != '\0')
	{
		diff = s1[index] - s2[index];
		if (diff != 0)
			break;
		index++;
	}
	return (diff);
}

/**
 *strconk - concatenates two strings.
 *@dest: destiny string
 *@src: source string
 *Return: dest
 */
char *strconk(char *dest, char *src)
{
	int n, i;

	for (n = 0; dest[n] != '\0'; n++)
	{
	}
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[n + i] = src[i];
	}
	dest[n + i] = '\0';

	return (dest);
}
