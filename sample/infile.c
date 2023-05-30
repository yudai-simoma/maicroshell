#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "../get_next_line/get_next_line_bonus.h"
#include "../header/libft.h"

/*
 * <, <<
 * 
 * cat < test.txt
 * cat << eof
 * 
 * cc infile.c ../get_next_line/get_next_line_bonus.c ../get_next_line/get_next_line_utils_bonus.c -o infile
 */
void ft_in_file(char *file_path)
{
	int fd;
	int cpfd;
	char *args[] = { "cat", NULL };

	fd = open(file_path, O_RDONLY);
	cpfd = dup(STDIN_FILENO);
	dup2(fd, STDIN_FILENO);
	execve("/bin/cat", args, NULL);
	dup2(cpfd, STDIN_FILENO);
	close(fd);
}

void ft_here_doc(char *target, char **envp)
{
	int pipefd[2];
	int cpfd;
	char *all_str = "";
	char *str;
	char *args[] = { "cat", NULL };
	pid_t pid;
	// int i = 0;

	while (1) {
		str = get_next_line(STDIN_FILENO);
		if (ft_strncmp(target, str, ft_strlen(target)) == 0) {
			break;
		}
		all_str = ft_strjoin(all_str, str);
	}

	pipe(pipefd);
	write(pipefd[1], all_str, ft_strlen(all_str));
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[1]);
	close(pipefd[0]);
	// close(STDIN_FILENO);
	// close(cpfd);
	execve("/bin/cat", args, envp);

}

int main(int argc, char **argv, char **envp)
{
	// ft_in_file("./test2.txt");
	ft_here_doc("eof", envp);
}
