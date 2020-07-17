#include <fcntl.h>

#include <stdio.h>
#include "../srcs/get_next_line.h"

int main()
{
	int fd;
	char	*line;

	line = NULL;
	fd = open("tol.txt", O_RDONLY);

	while(get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);

	return (0);
}
