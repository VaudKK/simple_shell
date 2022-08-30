#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	size_t buffer_size = 1024;
	char *buffer;

	buffer = (char *)malloc(sizeof(char) * buffer_size);

	printf("cisfun# ");
	getline(&buffer, &buffer_size,stdin);

	while(1)
	{
		printf("cisfun# ");
		getline(&buffer, &buffer_size,stdin);
	}
}
