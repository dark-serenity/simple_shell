#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

/**
 * display_prompt - Display the shell prompt
 */
void display_prompt(void);

/**
 * execute_command - Execute the specified command
 * @command: The command to be executed
 */
void execute_command(char *command);

#endif /* SIMPLE_SHELL_H */

