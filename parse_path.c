#include "shell.h"

/**
 * parse_path - Searches for the executable in the PATH environment.
 * @command: The command to search for.
 * @env: The environment variables.
 *
 * This function searches for the specified command within the directories
 * listed in the PATH environment variable. If found, it updates the 'command'
 * pointer with the full path to the executable.
 *
 * Return: 0 if found, -1 if not found.
 */
int parse_path(char **command, char **env)
{
char *token = NULL, *path_var = _get_path(env), *full_path = NULL;
size_t command_length = _strlen(*command), path_length;
struct stat st;

if (!path_var || stat(*command, &st) == 0)
return (path_var ? (free(path_var), -1) : -1);

token = strtok(path_var, ":");

while (token)
{
path_length = _strlen(token);
full_path = malloc(sizeof(char) * (path_length + command_length + 2));

if (!full_path)
return (free(path_var), -1);

full_path = _strcpy(full_path, token);
_strcat(full_path, "/");
_strcat(full_path, *command);

if (stat(full_path, &st) == 0)
{
*command = full_path;
free(path_var);
return (0);
}

free(full_path);
token = strtok(NULL, ":");
}

free(path_var);
return (-1);
}
