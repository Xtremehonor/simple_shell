#include "shell.h"

/**
 * find_executable - Searches for the executable in the PATH environment.
 * @command: The command to search for.
 * @env: The environment variables.
 * Return: 0 if found, -1 if not found.
 */
int parse_path(char **command, char **env)
{
char *token = NULL, *path_var = NULL, *full_path = NULL;
size_t command_length, path_length;
struct stat st;
    
    if (stat(*command, &st) == 0)
        return (-1);
/* Get the value of the "PATH" environment variable */
path_var = _get_path(env); 

    if (!path_var)
        return (-1);

token = strtok(path_var, ":"); /* Tokenize the "PATH" value */
command_length = _strlen(*command); /* Get the length of the command */
    
    while (token)
{
path_length = _strlen(token);
    full_path = malloc(sizeof(char) * (path_length + command_length + 2));

if (!full_path)
{
    free(path_var);
    return (-1);
}

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

token = '\0';
free(path_var);
return (-1);
}
