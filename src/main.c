/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:38:57 by yshimoma          #+#    #+#             */
/*   Updated: 2023/06/02 19:59:32 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

/*
- 実行可能ファイルのパスは絶対パスまたは相対パスです
- bashのように「|」と「;」を実装する必要があります。
- プログラムは組み込みのcdコマンドを実装する必要があります。
	- cdの引数の数が間違っている場合、プログラムは
	「error: cd: bad arguments\n」というエラーメッセージを標準エラー出力
	- cdに失敗した場合、プログラムは「error: cd: cannot change directory to path_to_change\n」
	というエラーメッセージを標準エラー出力に出力します。
	ここで、path_to_changeはcdの引数に置き換えられます。
- execveとchdir以外のシステムコールがエラーを返した場合、プログラムはすぐに標準エラー出力に
  「error: fatal」というメッセージを出力し、改行文字を出力してプログラムを終了する必要があります。
- プログラムは、「オープンされたファイル」の数を30以下に制限していても、何百もの「|」を
  処理できるようにする必要があります。

例えば、次のように動作するはずです:
$>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
microshell
i love my microshell
$>

TODO
	済Tokenizer
	・パーサー
	済"/bin/pwd"の実行
	済｜の実装
	・リダイレクション
	・ヒアドキュメント
	・リードラインループ
	・cdの実装（ビルドイン）
	・変数展開
	・スペースパラメータ
	・シグナル
	・；の実装
*/

int	ft_get_count(char *str, t_shell *shell)
{
	int	i;
	int j;

	i = 0;
	shell->pipe_count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '|')
			shell->pipe_count++;
		i++;
	}
	shell->pipe_count = shell->pipe_count;
	shell->input_redirect_count = ft_calloc(shell->pipe_count, sizeof(int));
	shell->output_redirect_count = ft_calloc(shell->pipe_count, sizeof(int));
	i = 0;
	j = 0;
	shell->input_redirect_count[j] = 0;
	shell->output_redirect_count[j] = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '<')
			shell->input_redirect_count[j]++;
		else if (str[i] == '>')
			shell->output_redirect_count[j]++;
		else if (str[i] == '|')
			j++;
		i++;
	}
	return (0);
}

/*
 * TODO:
 *  リダイレクトの処理を書く
 *  <, <<, 単体, パイプあり
 *  >, >>, 単体, パイプあり
 */
int	main(int argc, char **argv, char **envp)
{
	t_shell	shell_;
	int		i_;

	envp = NULL;
	argc = 0;
	shell_.args = ft_tokenizer(argc, argv);
	ft_get_count(argv[1], &shell_);
	i_ = 0;
	// 以下は、<の実装

	// 以下6行は、cmd | cmd の実装
	// while (i_ < shell_.pipe_count)
	// {
	// 	ft_cmd(&shell_, shell_.args[i_], envp);
	// 	i_++;
	// }
	// ft_put_execve(shell_.args[i_], envp);
	return (0);
}
