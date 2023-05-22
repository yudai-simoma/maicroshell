/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:41:48 by yshimoma          #+#    #+#             */
/*   Updated: 2023/05/22 20:50:50 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

void	ft_pipe(t_shell *shell, char **envp)
{
	int	i_;

	i_ = 0;
	while (i_ < shell->fork_count)
	{
		if (i_ + 1 != shell->fork_count)
			pipe(shell->pipefd);
		shell->pid = fork();
		if (shell->pid == 0)
		{
			close(shell->pipefd[READ]);
			if (i_ + 1 != shell->fork_count)
				dup2(shell->pipefd[WRITE], STDOUT_FILENO);
			close(shell->pipefd[WRITE]);
			ft_put_execve(shell->args[i_], envp);
		}
		else
		{
			close(shell->pipefd[WRITE]);
			if (i_ + 1 != shell->fork_count)
				dup2(shell->pipefd[READ], STDIN_FILENO);
			else
				close(shell->pipefd[READ]);
		}
		i_++;
	}
	i_ = 0;
	while (i_ < shell->fork_count)
	{
		wait(NULL);
		i_++;
	}
}
