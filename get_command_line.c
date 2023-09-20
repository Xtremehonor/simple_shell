#include "shell.h"

/**
 * get_command_line - Gets user input.
 *
 * Return: The input string.
 */
char *get_command_line(void)
{
	/* Initialize variables */
	char *lineptr = NULL;
	size_t charter_user = 0;

	/* Print shell prompt if STDIN is a terminal */
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	/* Read a line of input from the user */
	if (getline(&lineptr, &charter_user, stdin) <= 0)
	{
		free(lineptr); /* Clean up memory on error */
		return (NULL);
	}

	return (lineptr);
}
