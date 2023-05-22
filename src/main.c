/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:38:57 by yshimoma          #+#    #+#             */
/*   Updated: 2023/05/22 20:52:46 by yshimoma         ###   ########.fr       */
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
	済"/bin/pwd"の実行
	済｜の実装
	・cdの実装（ビルドイン）
	・リードラインループ
	・リダイレクション
	・ヒアドキュメント
	・変数展開
	・パーサー
	・スペースパラメータ
	・シグナル
	・；の実装
*/

int	ft_get_fork_count(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '|')
			count++;
		i++;
	}
	return (count);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell_;

	envp = NULL;
	argc = 0;
	shell_.args = ft_tokenizer(argc, argv);
	shell_.fork_count = ft_get_fork_count(argv[1]) + 1;
	ft_pipe(&shell_, envp);
	return (0);
}
