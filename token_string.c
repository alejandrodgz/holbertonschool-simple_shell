#include "shell.h"

/**
 * _token_string - tokenizes a string
 * @s: string to tokenize
 * @delimit: delimitator for the tokens
 *
 * Return: pointer to each token
 */

char *_token_string(char *s, char *delimit)
{
	int a;
	static char *string;

	if (!s)
		s = string;
	a = *s++;
	while (strchar(delimit, a))
	{
		if (a == 0)
			return (0);
		a = *s++;
	}
	--s;
	string = s + _strcspn(s, delimit);
	if (*string != 0)
	{
		*string = 0;
		string++;
	}
	return (s);
}

/**
 * strchar - locates a character in the string
 * @s: string
 * @b: Character
 *
 * Return: pointer to the first occurrence of the character
 */

char *strchar(char *s, char b)
{
	while (*s != 0)
	{
		if (*s == b)
		{
			return (s);
		}
		s++;
	}
	if (*s == b)
	{
		return (s);
	}
	return (0);
}

/**
 * _strcspn - gets the lenght of a prefix string
 * @s: string
 * @pre: prefix string
 *
 * Return: number of bytes in the initial seg of s
 */

unsigned int _strcspn(char *s, char *pre)
{
	unsigned int lenght = 0, a = 0;

	while (s[lenght] != 0)
	{
		int flag = 0;

		for (a = 0; pre[a] != 0; a++)
		{
			if (s[lenght] == pre[a])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			lenght++;
		}
		else
			break;
	}
	return (lenght);
}
