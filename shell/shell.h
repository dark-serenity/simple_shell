#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

/**
 * display_prompt - Display a simple shell prompt.
 */
void display_prompt(void);

#endif /* SHELL_H */

