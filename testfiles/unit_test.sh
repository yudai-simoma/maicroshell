#!/bin/bash

# 第一引数の値によってシェルを変更
shellname=$1
if [ "$shellname" = "bash" ]
then
	my_shell="/bin/bash"
elif [ "$shellname" = "zsh" ]
then
	my_shell="/bin/zsh"
else
	my_shell="./microshell"
fi

# 基本的なコマンドの実行
echo "実行したシェルは" $shellname "です"
echo "ls" | $my_shell
echo "pwd" | $my_shell
echo "echo hello world" | $my_shell

# ビルトインコマンドの動作
echo "Testing built-in commands..."
echo "cd .." | $my_shell
echo "exit" | $my_shell
echo "export TEST_VAR=123" | $my_shell
echo "unset TEST_VAR" | $my_shell
echo "env" | $my_shell

# 引数付きのコマンド
echo "Testing commands with arguments..."
echo "ls -l" | $my_shell
echo "echo -n hello world" | $my_shell

# パイプラインの実行
echo "Testing pipelines..."
echo "ls -l | grep .txt" | $my_shell

# リダイレクションの実行
echo "Testing redirection..."
echo "echo hello > testfile" | $my_shell
echo "cat < testfile" | $my_shell
echo "rm testfile" | $my_shell

# 環境変数の扱い
echo "Testing handling of environment variables..."
echo "export TEST_VAR=123; echo \$TEST_VAR" | $my_shell

echo "All tests done."
