#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

#include "main.h"

char *getInput()
{
	size_t len;
	char *line = NULL;
	len = getline(&line, &len, stdin);

	if (line[len - 1] == '\n')
		line[len - 1] ='\0';

	return (line);
}

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

int main(void)
{
	char *line = NULL;
	char **tokens;
	char *envp[] = {"PATH=/bin",NULL};
	pid_t proc_id;
	int status, file_found;
	struct stat st;

	while (1)
	{
		printf("cisfun# ");
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
