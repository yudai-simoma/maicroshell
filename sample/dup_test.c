#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	// ファイルを開く（存在しない場合は作成する）
	int file_desc = open("test.txt", O_WRONLY | O_CREAT, 0644);
	if (file_desc < 0)
	{
		perror("Failed to open file");
		return (1);
	}

	printf("この文字はターミナルに書き込まれる\n");

	// STDOUT（ファイル記述子 1）を保存しておく
	int saved_stdout = dup(1);

	// STDOUTをファイル記述子にリダイレクト
	if (dup2(file_desc, 1) < 0)
	{
		perror("Failed to redirect stdout");
		return (1);
	}

	// これ以降、printfの出力はtest.txtに書き込まれる
	printf("この文字はtest.txtに書き込まれる\n");
	printf("Hello, World!\n");

	// STDOUTを元に戻す
	dup2(saved_stdout, 1);

	// これ以降、printfの出力はコンソールに表示される
	printf("Back to console output.\n");

	close(file_desc);

	return (0);
}