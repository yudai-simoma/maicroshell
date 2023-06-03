#include <stdio.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>

int	main(void)
{
	char	*line;

	// ユーザから行を読み取る
	line = readline("> ");
	if (line == NULL)
	{
		printf("No input received.\n");
		return (0);
	}
	// 読み取った行を履歴に追加する
	add_history(line);
	// readline関数が表示するプロンプトの行を変更する
	rl_replace_line("Replaced line", 0);
	// 行の変更を画面に表示する
	rl_redisplay();
	// 履歴をクリアする
	rl_clear_history();
	// 新しい行の開始を示す
	rl_on_new_line();
	// 終了前にもう一度プロンプトを表示する
	line = readline("> ");
	free(line); // readline()関数によって割り当てられたメモリを解放する
	return (0);
}

// #include <readline/history.h>
// #include <readline/readline.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*line;

// 	line = NULL;
// 	while (1)
// 	{
// 		line = readline("> ");
// 		if (line == NULL || strlen(line) == 0)
// 		{
// 			free(line);
// 			break ;
// 		}
// 		printf("line is '%s'\n", line);
// 		add_history(line);
// 		free(line);
// 	}
// 	printf("exit\n");
// 	return (0);
// }
