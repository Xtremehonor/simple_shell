#include "shell.h"

/**
 * tokenize_input - Tokenizes a string.
 *
 * @line_input: The input string.
 *
 * Return: A pointer to an array of pointers.
 */
char **tokenize_input(char *line_input)
{
	char **command_tokens = NULL;
	char *token = NULL;
	size_t count_tokens = 0;

	if (line_input == NULL)
		return (NULL);

	size_t i = 0;
	while (line_input[i])
	{
		if (line_input[i] == ' ')
			count_tokens++;
		i++;
	}

	if ((count_tokens + 1) == _strlen(line_input))
		return (NULL);

	command_tokens = malloc(sizeof(char *) * (count_tokens + 2));
	if (command_tokens == NULL)
		return (NULL);

	token = strtok(line_input, " \n\t\r");

	size_t token_index = 0;
	while (token != NULL)
	{
		command_tokens[token_index] = token;
		token = strtok(NULL, " \n\t\r");
		token_index++;
	}

	command_tokens[token_index] = NULL;
	return (command_tokens);
}
