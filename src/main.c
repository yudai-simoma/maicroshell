/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:38:57 by yshimoma          #+#    #+#             */
/*   Updated: 2023/05/21 21:19:45 by yshimoma         ###   ########.fr       */
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
	・｜の実装
	・；の実装
	・cdの実装（ビルドイン）
	・リードラインループ
	・リダイレクション
	・ヒアドキュメント
	・変数展開
	・パーサー
	・スペースパラメータ
	・シグナル
*/

int	main(int argc, char **argv, char **envp)
{
	envp = NULL;
	argc = 0;
	char	**args_;
	int		pipefd_[2];
	pid_t	pid_;

	args_ = ft_tokenizer(argc, argv);
	ft_put_execve(args_, envp);
	pipe(pipefd_);
	pid_ = fork();
	// if (pid_ == 0)
	// {
		
	// }
	// else
	// {
		
	// }
	return (0);
}
