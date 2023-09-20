#include "shell.h"

/**
 * print_environment - Prints environment variables to standard output.
 *
 * @env: The environment variables.
 */
void print_environment(char **env)
{
	size_t run = 0;

	while (env[run])
	{
		/* Write environment variable to standard output */
		write(STDOUT_FILENO, env[run], _strlen(env[run]));
		/* Write a newline character to separate variables */
		write(STDOUT_FILENO, "\n", 1);
		run++;
	}
}
