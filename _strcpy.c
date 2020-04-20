/**
 * _strcpy - unction that copies the string pointed to by src
 *@dest: char
 *@src:_ char
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0, j;

	while (src[i] != '\0')
	{
		i++;
	}
	for (j = 0; j <= i; j++)
	{
		dest[j] = src[j];
	}
	return (dest);
}
