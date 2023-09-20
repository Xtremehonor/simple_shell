#include "shell.h"

/**
 * get_command_line - Gets user input.
 *
 * Return: The input string.
 */
char *get_command_line(void)
{
    /* Initialize variables */
    char *user_input = NULL;
    size_t input_size = 0;

    /* Print shell prompt if STDIN is a terminal */
    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ", 2);

    /* Read a line of input from the user */
    if (getline(&user_input, &input_size, stdin) <= 0)
    {
        free(user_input); /* Clean up memory on error */
        return (NULL);
    }

    return (user_input);
}
