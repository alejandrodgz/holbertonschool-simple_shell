#include "shell.h"

/**
 * _str_comparation - compares two strings
 * @s1: string one
 * @s2: string two
 * Return: 0 if match, anything else if they don't match
 */
int _str_comparation(char *s1, char *s2)
{
	int i = 0, c = 0, greater;
	int len1, len2;

	if (!s1 || !s2)
		return (-1);

	len1 = _str_lenght(s1);
	len2 = _str_lenght(s2);

	if (!len1 || !len2)
		return (-1);

	while (s1[i] != 0 && s2[i] != 0)
	{
		if (s1[i] == s2[i])
		{
			c++;
		}
		i++;
	}
	greater = len1 > len2 ? len1 : len2;
	if (c == greater)
		return (0);
	return (-1);
}

/**
 * _str_lenght - lenght of string
 * Return: length of string
 * @s: string
 */

int _str_lenght(char *s)
{
	int quot = 0;

	if (!s)
	{
		return (quot);
	}
	while (s[quot] != 0)
	{
		quot++;
	}
	return (quot);
}

/**
 * _string_cat - concatenates two strings
 * @str1: first string
 * @str2: second string to be concatenated
 * Return: pointer to the concatenated string
 */

char *_string_cat(char *str1, char *str2)
{
	char *cat_string;
	int lenght1 = _str_lenght(str1), lenght2 = _str_lenght(str2), it, it2;

	cat_string = malloc(sizeof(char) * (lenght1 + lenght2 + 1));
	if (cat_string == NULL)
	{
		printf("Error: impossible to  allocate memory");
		exit(98);
	}
	for (it = 0; str1[it] != '\0'; it++)
	{
		cat_string[it] = str1[it];
	}
	for (it2 = 0; str2[it2] != '\0'; it2++)
	{
		cat_string[it + it2] = str2[it2];
	}
	cat_string[it + it2] = '\0';
	return (cat_string);
}

/**
 * _string_dup - gives a pointer to memory space
 * @string: string
 * Return: pointer
 */

char *_string_dup(char *string)
{
	char *s;
	unsigned int size = 0, a;

	if (string == NULL)
	{
		return (NULL);
	}
	while (*(string + size))
		size++;

	s = malloc(sizeof(char) * (size + 1));

	if (s == NULL)
		return (NULL);

	for (a = 0; a < size; a++)
		*(s + a) = *(string + a);

	*(s + size) = '\0';

	return (s);
}

/**
 * _str_copy - prints string
 * @dest: destiny string
 * @src: source string
 *
 * Return: lenght of the string
 */
char *_str_copy(char *dest, char *src)
{
	int s = 0;

	int i;

	while (src[s] != 0)
	{
		s++;
	}

	dest[s] = '\0';
	for (i = 0; i < s; i++)
		dest[i] = src[i];

	return (dest);
}
