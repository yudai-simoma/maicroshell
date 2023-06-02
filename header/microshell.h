/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:49:46 by yshimoma          #+#    #+#             */
/*   Updated: 2023/06/02 19:40:57 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H
# include <string.h> // strcmp
# include <unistd.h> // write, close, dup, dup2, close, execve, chdir and fork
# include <sys/wait.h> // waitpid
# include <stdlib.h> //malloc, free
# include <signal.h> //kill, signal
# include <stdio.h>
# include <stdbool.h>
# include "libft.h"
// # include "get_next_line_bonus.h"

# define RED_COLOR "\033[31m"
# define RESET_COLOR "\033[0m"

# define READ 0
# define WRITE 1

typedef struct s_shell
{
	char	***args;
	int		pipefd[2];
	pid_t	pid;
	int		pipe_count;
	int		*input_redirect_count;
	int		*output_redirect_count;
}	t_shell;

//put_execve.c
void	ft_put_execve(char **args, char **envp);
//tokenizer.c
char	***ft_tokenizer(int argc, char **argv);
//pipe.c
void	ft_pipe(t_shell *shell, char **envp);
//cmd.c
void	ft_cmd(t_shell *shell, char **execve_str, char **envp);

#endif