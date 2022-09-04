#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	char *line = NULL;
	size_t len;
	char *token;
	char **tokens;
	char *envp[] = {NULL};
	pid_t proc_id;
	int status, i = 1;

	while (1)
	{
		printf("cisfun# ");
		len = getline(&line, &len, stdin);
		tokens = (char **)malloc((sizeof(char) * len) + len);
		token = strtok(line, " ");
		tokens[0] = token;
		while (token != 0)
		{
			token = strtok(0, " ");
			tokens[i] = token;
			i++;
		}
		if (line[len -1] == '\n')
			line[len - 1] = '\0';

		proc_id = fork();

		// run the command in the child process
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
			free(tokens);
		}
		
	}
}
