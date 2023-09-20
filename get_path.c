#include "shell.h"

/**
 * _get_path - Gets the value of the PATH environment variable.
 * @env: The local environment.
 *
 * Return: The value of the PATH variable.
 */
char *_get_path(char **env)
{
    size_t env_index = 0, char_index = 0, path_length = 5;
    char *path = NULL;

    /* Find the index of the PATH variable */
    while (_strncmp(env[env_index], "PATH=", path_length))
        env_index++;

    /* If PATH is not found, return NULL */
    if (env[env_index] == NULL)
    {
        return (NULL);
    }

    /* Calculate the length of the PATH string */
    for (path_length = 5; env[env_index][char_index]; char_index++, path_length++)
        ;

    /* Allocate memory for the PATH string */
    path = malloc(sizeof(char) * (path_length + 1));

    /* Check if memory allocation was successful */
    if (path == NULL)
    {
        return (NULL);
    }

    /* Copy the PATH string to the allocated memory */
    for (char_index = 5, path_length = 0; env[env_index][char_index]; char_index++, path_length++)
        path[path_length] = env[env_index][char_index];

    path[path_length] = '\0'; /* Add null terminator */
    return (path);
}
