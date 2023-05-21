#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
	int pipefd[2];
	char buffer[BUFFER_SIZE];
	pid_t pid;

	if (pipe(pipefd) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	pid = fork();
	if (pid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0) {
		close(pipefd[1]);
		while (read(pipefd[0], buffer, BUFFER_SIZE) > 0) {
			printf("Child received: %s\n", buffer);
		}
		close(pipefd[0]);
	} else {
		close(pipefd[0]);
		char *message = "Hello, child!";
		write(pipefd[1], message, strlen(message) + 1);
		close(pipefd[1]);
	}

	return 0;
}