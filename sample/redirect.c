#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

/*
 * >
 */
void ft_file_write(char *file_path, char *str)
{
	int	fd;
	int cpfd;

	fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	cpfd = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	printf("%s", str);
	fflush(stdout);  // stdoutのバッファをフラッシュ
	dup2(cpfd, STDOUT_FILENO);
	close(fd);
}

/*
 * >>
 */
void ft_file_over_write(char *file_path, char *str)
{
	int	fd;
	int	cpfd;

	fd = open(file_path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	cpfd = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	printf("%s", str);
	fflush(stdout);  // stdoutのバッファをフラッシュ
	dup2(cpfd, STDOUT_FILENO);
	close(fd);
}

int main()
{
	ft_file_write("./test.txt", "ccc\n");
	ft_file_over_write("./test2.txt", "eee\n");
}
