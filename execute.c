#include "shell.h"

int change_directory(char **args);
int display_help(char **args);
int exit_shell(char **args);
int handle_ctrl_d(char **args);

char *builtin_commands[] = {"cd", "help", "exit", "^D"};

int (*builtin_functions[]) (char **) = {&change_directory,
  &display_help, &exit_shell, &handle_ctrl_d};

/**
 * count_builtin_commands - Returns the number of built-in commands.
 * Return: Number of built-in commands.
 */
int count_builtin_commands(void)
{
return (sizeof(builtin_commands) / sizeof(char *));
}

/**
 * change_directory - Changes the current working directory.
 * @args: List of arguments. args[0] is "cd", args[1] is the directory.
 * Return: 1 on success, 0 otherwise.
 */
int change_directory(char **args)
{
if (args[1] == NULL)
{
fprintf(stderr, "hsh: expected argument to \"cd\"\n");
}
    else
    {
        if (chdir(args[1]) != 0)
        {
            perror("hsh");
        }
    }
    return (1);
}

/**
 * display_help - Prints help for the shell.
 * @args: List of arguments. Not examined.
 * Return: Always returns 1 to continue executing.
 */
int display_help(char **args)
{
    int i = 0;

    printf("Getayawkal Wondimagegnehu\nIf you need assistance, +251 ...\n");
    (void)args;

    while (i < count_builtin_commands())
    {
        printf("  %s\n", builtin_commands[i]);
        i++;
    }

    return (1);
}

/**
 * exit_shell - Exits the shell.
 * @args: List of arguments. Not examined.
 * Return: Always returns 200 to terminate execution.
 */
int exit_shell(char **args)
{
    (void)args;
    free(args);
    return (200);
}

/**
 * handle_ctrl_d - Handles "^D" call.
 * @args: List of arguments. Not examined.
 * Return: Always returns 200 to terminate execution.
 */
int handle_ctrl_d(char **args)
{
    (void)args;
    free(args);
    return (200);
}

/**
 * fork_and_execute - Creates a fork to execute a command.
 * @command_tokens: List of command tokens.
 * @program_name: Name of the program.
 * @environment: Environment variables.
 * @user_input: User input string.
 * @process_id: Process ID.
 * @new_test_checker: Checker for new test.
 *
 * Return: 0 on success.
 */
int fork_and_execute(char **command_tokens, char **program_name, char **environment, char *user_input, int process_id, int new_test_checker)
{
pid_t child;
int status, i = 0;
char *format = "%s: %d: %s: command not found\n";

if (command_tokens[0] == NULL)
    return (1);
for (i = 0; i < count_builtin_commands(); i++)
{
    if (string_compare(command_tokens[0], builtin_commands[i]) == 0)
    return (builtin_functions[i](command_tokens));
}
child = fork();
if (child == 0)
{
if (execve(command_tokens[0], command_tokens, environment) == -1)
{
fprintf(stderr, format, program_name[0], process_id, command_tokens[0]);
    if (!new_test_checker)
        free(command_tokens[0]);
    free(command_tokens);
    free(user_input);
    exit(errno);
        }
}
else
{
wait(&status);
    return (status);
}
return (0);
}
