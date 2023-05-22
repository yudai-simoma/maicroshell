/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:40:52 by yshimoma          #+#    #+#             */
/*   Updated: 2023/05/22 20:20:06 by yshimoma         ###   ########.fr       */
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
 * コマンドの実行関数
 *
 * TODO:コマンドのパスを探す。リーク確認。エラー処理
 * /bin/ls -l
 */
void	ft_put_execve(char **args, char **envp)
{
	char	*file_path_;

	// file_path_ = ft_set_path(args[0], getenv("PATH"));
	// TODO:getenvで$PATHを渡す
	file_path_ = _ft_set_path(args[0], "/bin");
	if (file_path_ == NULL)
		return ;
	if (execve(file_path_, args, envp) < 0)
	{
		perror("execve error");
		exit (EXIT_FAILURE);
	}
}
