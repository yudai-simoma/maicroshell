/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:22:33 by yshimoma          #+#    #+#             */
/*   Updated: 2023/06/03 14:07:59 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

/*
 * cmd |
 */
void	ft_pipe_cmd(t_shell *shell, int index, char **envp)
{
	pipe(shell->pipefd);
	shell->pid = fork();
	if (shell->pid == 0)
	{
		close(shell->pipefd[READ]);
		ft_put_execve(shell, index, envp);
		close(shell->pipefd[WRITE]);
	}
	else
	{
		close(shell->pipefd[WRITE]);
		dup2(shell->pipefd[READ], STDIN_FILENO);
		close(shell->pipefd[READ]);
	}
	wait(NULL);
}

void	ft_cmd(t_shell *shell, int index, char **envp)
{
	ft_put_execve(shell, index, envp);
}
