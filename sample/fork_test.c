
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (1);
	}
	else if (pid == 0)
		printf("子プロセスの処理, fork_pid = %d, main_pid = %d\n", pid, getpid());
	else
		printf("親プロセスの処理, fork_pid = %d, main_pid = %d\n", pid, getpid());
	return (0);
}
