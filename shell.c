#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *line = NULL;
	ssize_t len = 0;
	char *arguments[] = {"", NULL};
	char *envp[] = {NULL};

	while (1)
	{
		printf("cisfun# ");
		len = getline(&line, &len, stdin);

		if (line[len -1] == '\n')
			line[len - 1] = '\0';

		if (execve(line, arguments, envp) == -1)
		{
			perror("./shell");
		}
	}
}
