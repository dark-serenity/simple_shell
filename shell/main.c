#include "shell.h"

int main(void)
{
    char input[MAX_INPUT_SIZE];
    pid_t pid;

    while (1)
    {
        display_prompt();

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("\n");
            break; /* End of file (Ctrl+D) is encountered */
        }

        /* Remove newline character from input */
        input[strcspn(input, "\n")] = '\0';

        /* Fork a child process */
        pid = fork();

        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            /* Child process */

            /* Execute the command using execve */
            char *argv[] = {input, NULL};
            char *envp[] = {NULL};
            if (execve(input, argv, envp) == -1)
            {
                /* Executable not found */
                perror("execve");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            /* Parent process */
            int status;
            waitpid(pid, &status, 0);

            if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
            {
                /* Executable found, but an error occurred */
                printf("./shell: %s: command not found\n", input);
            }
        }
    }

    return (0);
}

void display_prompt(void)
{
    printf("#cisfun$ ");
    fflush(stdout);
}

