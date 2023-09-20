#include "shell.h"
/**
 * tokenize_input - tokenizes a string
 * @user_input: what the user inputed
 * Return: a ptr to arr of ptrs
 */
char **tokenize_input(char *user_input)
{
char **command_tokens = NULL;
char *token = NULL;
size_t index = 0;
int size = 0;

if (user_input == NULL)
return (NULL);

for (index = 0; user_input[index]; index++)
{
if (user_input[index] == ' ')
size++;
}
if ((size + 1) == _strlen(user_input))
return (NULL);
command_tokens = malloc(sizeof(char *) * (size + 2));
if (command_tokens == NULL)
return (NULL);

token = strtok(user_input, " \n\t\r");

for (index = 0; token != NULL; index++)
{
command_tokens[index] = token;
token = strtok(NULL, " \n\t\r");
}
command_tokens[index] = NULL;
return (command_tokens);
}
