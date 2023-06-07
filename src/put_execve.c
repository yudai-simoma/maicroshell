/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:40:52 by yshimoma          #+#    #+#             */
/*   Updated: 2023/06/07 19:11:03 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

/*
 * コマンドのファイルパスを探す
 * TODO:envの$PATHからコマンドのパスを探す。freeを行う
 */
static char	*_ft_set_path(char *path, char *env)
{
	char	*file_path_;

	file_path_ = ft_strjoin(env, "/");
	file_path_ = ft_strjoin(file_path_, path);
	// ファイルの存在と読み取り可能性をチェック
	if (access(file_path_, F_OK | R_OK | X_OK) != 0)
	{
		printf(RED_COLOR "access error path\n" RESET_COLOR);
		return (NULL);
	}
	else
	{
		return (file_path_);
	}
}

/*
 * >
 */
void ft_out_file(char *file_path)
{
	int fd;

	fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

char	*_ft_get_redirect_path(char **args)
{
	int		i;

	i = 0;
	while (args[i] != NULL)
	{
		if (ft_strchr(args[i], '<') != NULL)
			return (args[i + 1]);
		else if (ft_strchr(args[i], '>') != NULL)
			return (args[i + 1]);
		i++;
	}
	return (NULL);
}

char	**_ft_get_execve_path(char **args)
{
	int		i;

	i = 0;
	while (args[i] != NULL)
	{
		if (ft_strchr(args[i], '<') != NULL)
		{
			args[i] = NULL;
			return (args);
		}
		else if (ft_strchr(args[i], '>') != NULL)
		{
			args[i] = NULL;
			return (args);
		}
		i++;
	}
	return (args);
}

/*
 * コマンドの実行関数
 * パイプあり
 *
 * TODO:コマンドのパスを探す。リーク確認。エラー処理
 * /bin/ls -l
 */
void	ft_put_execve(t_shell *shell, int index, char **envp)
{
	char	*file_path;
	char	**cmd_str;

	// file_path = ft_set_path(args[0], getenv("PATH"));
	// TODO:getenvで$PATHを渡す
	// printf("ft_put_execve type = %d, index = %d\n", shell->cmd_type[index], index);
	if (shell->cmd_type[index] == OUT_FILE)
	{
		file_path = _ft_get_redirect_path(shell->args[index]);
		printf("file_path = %s\n", file_path);
		ft_out_file(file_path);
		cmd_str = _ft_get_execve_path(shell->args[index]);
	}
	// else if (shell->cmd_type[index] == OVER_OUT_FILE)
	// else if (shell->cmd_type[index] == IN_FILE)
	else if (shell->cmd_type[index] == NORMAL)
	{
		dup2(shell->pipefd[WRITE], STDOUT_FILENO);
		cmd_str = shell->args[index];
	}
	file_path = _ft_set_path(shell->args[index][0], "/bin");
	if (file_path == NULL)
		return ;
	if (execve(file_path, cmd_str, envp) < 0)
	{
		perror("execve error");
		exit (EXIT_FAILURE);
	}
}

/*
 * コマンドの実行関数
 * パイプなし
 *
 * TODO:コマンドのパスを探す。リーク確認。エラー処理
 * /bin/ls -l
 */
void	ft_end_execve(t_shell *shell, int index, char **envp)
{
	char	*file_path;
	char	**cmd_str;

	// file_path = ft_set_path(args[0], getenv("PATH"));
	// TODO:getenvで$PATHを渡す
	// printf("ft_put_execve type = %d, index = %d\n", shell->cmd_type[index], index);
	if (shell->cmd_type[index] == OUT_FILE)
	{
		file_path = _ft_get_redirect_path(shell->args[index]);
		printf("file_path = %s\n", file_path);
		ft_out_file(file_path);
		cmd_str = _ft_get_execve_path(shell->args[index]);
	}
	// else if (shell->cmd_type[index] == OVER_OUT_FILE)
	// else if (shell->cmd_type[index] == IN_FILE)
	else if (shell->cmd_type[index] == NORMAL)
	{
		cmd_str = shell->args[index];
	}
	file_path = _ft_set_path(shell->args[index][0], "/bin");
	if (file_path == NULL)
		return ;
	if (execve(file_path, cmd_str, envp) < 0)
	{
		perror("execve error\n");
		exit (EXIT_FAILURE);
	}
}
