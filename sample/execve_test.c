#include <stdio.h>
#include <unistd.h>

// int main() {
//     char* filename = "/bin/ls";
//     char* argv[] = { "ls", "-l", NULL };
// 	//新しく実行するプロセスに環境変数を設定することができる
//     char* envp[] = { "PATH=/usr/bin:/bin", "TERM=xterm", NULL };

//     if (execve(filename, argv, envp) < 0) {
//         perror("execve");
//         return 1;
//     }

//     // execve()が成功すると、このプロセスは/bin/lsに置き換えられ、以下のコードは実行されません

//     return 0;
// }

int main() {
    char *binaryPath = "/bin/ls";
    char *args[] = { "ls", "-la", NULL };  // コマンドライン引数の配列
    char *envp[] = { NULL };  // 環境変数の配列

    execve(binaryPath, args, envp);

    // execve()が成功すれば、この行は実行されません。
    // execve()が失敗した場合のみ、以下の行が実行されます。
    perror("execve failed");
    return 1;
}