#include <stdio.h>
#include <stdlib.h>
#include <readline/history.h>
#include <readline/readline.h>

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
	// 履歴に行を追加
	add_history(line);
	// readline関数が表示するプロンプトの行を変更する
	rl_replace_line("Replaced line", 0);
	// 行の変更を画面に表示する
	rl_redisplay();
	// 新しい行の開始を示す
	rl_on_new_line();
	// rl_redisplay()の後でprintf()を使って行を表示
	printf("\n%s\n", line);
	// readline()関数によって割り当てられたメモリを解放する
	free(line);
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
