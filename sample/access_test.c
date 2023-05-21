#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	const char *filepath = "/bin/ls";  // チェックするファイルのパス
	const char *filepath1 = "/tmp/ls"; // チェックするファイルのパス
	// ファイルの存在と読み取り可能性をチェック
	if (access(filepath, F_OK | R_OK) != 0)
	{
		perror("access error path");
	}
	else
	{
		printf("File exists and is readable. path = %s\n", filepath);
	}
	// ファイルの存在と読み取り可能性をチェック
	if (access(filepath1, F_OK | R_OK) != 0)
	{
		perror("access error");
	}
	else
	{
		printf("File exists and is readable. path = %s\n", filepath1);
	}
	return (0);
}
