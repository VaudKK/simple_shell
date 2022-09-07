#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

#include "main.h"
/**
 * getInput -- gets input from  user
 *
 * Return: the string of the line
 */
char *getInput()
{
	size_t len;
	char *line = NULL;

	len = getline(&line, &len, stdin);

	if (line[len - 1] == '\n')
		line[len - 1] = '\0';

	return (line);
}
/**
 * getTokens - gets the argumenst from the line
 * @line: the line from the user
 *
 * Return: pointer to tokens
 */
char **getTokens(char *line)
{
	char *tokens[20];
	char *token;
	int i = 1, j = 0;
	char **tokens_ptr = malloc(20 * sizeof(char *));

	token = strtok(line, " ");
	tokens[0] = token;

	while (token != NULL)
	{
		token = strtok(NULL, " ");
		tokens[i] = token;
		i++;
	}

	while (tokens[j] != NULL)
	{
		tokens_ptr[j] = tokens[j];
		j++;
	}

	return (tokens_ptr);
}
/**
 * main - executes the arguments
 *
 * Return: nothing
 */
int main(void)
{
	char *line = NULL;
	char **tokens;
	char *envp[] = {"PATH=/bin", NULL};
	pid_t proc_id;
	int status, file_found;
	struct stat st;

	while (1)
	{
		write(1, "($) ", 4);
		line = getInput();

		tokens = getTokens(line);
		
		file_found = file_exists(tokens[0], &st);
		if (file_found != 0)
			continue;
		proc_id = fork();
		if (proc_id == 0)
		{
			if (execve(tokens[0], tokens, envp) == -1)
			{
				perror("./shell");
			}
		}
		if (proc_id != 0)
		{
			wait(&status);
		}
	}
}
