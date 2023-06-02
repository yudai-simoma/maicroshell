/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:22:33 by yshimoma          #+#    #+#             */
/*   Updated: 2023/06/02 18:55:00 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

/*
 * cmd |
 */
void	ft_cmd(t_shell *shell, char **execve_str, char **envp)
{
	pipe(shell->pipefd);
	shell->pid = fork();
	if (shell->pid == 0)
	{
		close(shell->pipefd[READ]);
		dup2(shell->pipefd[WRITE], STDOUT_FILENO);
		ft_put_execve(execve_str, envp);
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
