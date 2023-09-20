#include "shell.h"
/**
* main - Main function for handling shell operations.
* @argc: Argument count.
* @argv: Argument vector.
* @envp: Environment variables.
* Return: Exit status (0 on success).
*/
int main(int argc, char **argv, char **envp)
{
int path_flag = 0, status = 0, is_path = 0;
char *input_line = NULL, **command_tokens = NULL;
while (1) /* Infinite loop for shell operation */
{
errno = 0;
input_line = get_command_line(); /* Read user input */
if (input_line == NULL && errno == 0)
return (0);
if (input_line)
{
path_flag++;
command_tokens = tokenize_input(input_line); /* Tokenize user input */
if (!command_tokens)
free(input_line);
if (!string_compare(command_tokens[0], "env"))
{
print_environment(envp);
}
else
{
is_path = parse_path(&command_tokens[0], envp); /* Tokenize PATH variable */
status = fork_and_execute(command_tokens,
argv, envp, input_line, path_flag, is_path);
if (status == 200)
{
free(input_line);
return (0);
}
if (is_path == 0)
free(command_tokens[0]);
}
free(command_tokens); /* Free allocated memory */
}
else
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1); /* Write to standard output */
exit(status);
}
free(input_line);
}
return (status);
}
