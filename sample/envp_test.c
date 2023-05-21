#include <stdio.h>

int	main(int ac, char **av, char **env)
{
	// Print all command-line arguments
	for (int i = 0; i < ac; ++i)
	{
		printf("Command-line argument %d: %s\n", i, av[i]);
	}
	// Print all environment variables
	for (char **envp = env; *envp != 0; envp++)
	{
		// printf("Environment variable: %s\n", *envp);
	}
	return (0);
}
