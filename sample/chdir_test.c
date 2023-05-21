#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	if (chdir("/tmp") == 0)
	{
		printf("Changed directory to /tmp successfully.\n");
	}
	else
	{
		perror("Failed to change directory");
	}
	return (0);
}
