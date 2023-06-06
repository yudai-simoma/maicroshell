/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:22:33 by yshimoma          #+#    #+#             */
/*   Updated: 2023/06/06 20:12:47 by yshimoma         ###   ########.fr       */
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
	shell->pid = fork();
	if (shell->pid < 0)
	{
		printf("fork error\n");
		return ;
	}
	if (shell->pid == 0)
	{
		ft_end_execve(shell, index, envp);
		printf("hoghog\n");
	}
	else
	{
		wait(NULL);
		printf("hoehoe\n");
	}
}
