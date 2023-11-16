#include "simple_shell.h"

/**
 * main - Entry point of the program
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];

	while (1)
	{
		display_prompt();

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			/* Handle end of file (Ctrl+D) */
			printf("\n");
			break;
		}

		/* Remove newline character */
		input[strcspn(input, "\n")] = '\0';

		/* Check for exit command */
		if (strcmp(input, "exit") == 0)
		{
			break;
		}

		/* Execute the command */
		execute_command(input);
	}

	printf("Shell terminated.\n");

	return (EXIT_SUCCESS);
}

/**
 * display_prompt - Display the shell prompt
 */
void display_prompt(void)
{
	printf("#cisfun$ ");
	fflush(stdout);
}

/**
 * execute_command - Execute the specified command
 * @command: The command to be executed
 */
void execute_command(char *command)
{
	char *args[2];
	pid_t child_pid;
	int status;

	/* Fork a child process */
	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		/* Child process */
		args[0] = command;
		args[1] = NULL;

		/* Execute the command */
		execve(args[0], args, NULL);

		/* If execve fails */
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		waitpid(child_pid, &status, 0);
	}
}

