#include "shell.h"

/**
 * _strcat - Concatenates two strings.
 *
 * @dest: Destination string.
 * @src: Source string.
 *
 * Return: A pointer to the concatenated string.
 */
char *_strcat(char *dest, char *src)
{
	int i, j = 0;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * string_compare - Compares two strings.
 *
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: The difference between the two strings.
 */
int string_compare(char *s1, char *s2)
{
	int i = 0;
	int val;

	while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i])
		i++;
	val = s1[i] - s2[i];
	return (val);
}

/**
 * _strlen - Gets the length of a string.
 *
 * @s: The string to measure.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != 0; i++)
		;

	return (i);
}

/**
 * _strncmp - Compares two strings up to a specified length.
 *
 * @s1: The first string.
 * @s2: The second string.
 * @n: The number of characters to compare.
 *
 * Return: The difference between the two strings.
 */
size_t _strncmp(char *s1, char *s2, size_t n)
{
	size_t i, j;

	for (j = 0; s1[j] != '\0' && j < n; j++)
	{
		i = s1[j] - s2[j];

		if (i != 0)
		{
			return (i);
		}
	}
	return (0);
}

/**
 * _strcpy - Copies the string pointed to by src into dest.
 *
 * @dest: Destination of the copy.
 * @src: Source of the copy.
 *
 * Return: A char pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i + 1] = 0;
	return (dest);
}