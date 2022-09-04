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
	char *arguments[] = {"", NULL};
	char *envp[] = {NULL};
	pid_t proc_id;
	int status;

	while (1)
	{
		printf("cisfun# ");
		len = getline(&line, &len, stdin);
		token = (char *)malloc(sizeof(char) * len);
		strtok_r(line, " ", token);
		if (line[len -1] == '\n')
			line[len - 1] = '\0';

		proc_id = fork();

		// run the command in the child process
		if (proc_id == 0)
		{
			if (execve(token[0], token, envp) == -1)
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
