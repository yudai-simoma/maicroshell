#!/bin/bash

# for each argument provided to the script
for file in "$@"
do
  # 実行ファイルをすべて削除
  if [ ${file} == "delete" ]; then
    # for each file in the current directory
    for file in *
    do
      # if the file is an executable and has no extension
      if [ -x "$file" ] && { [ "${file##*.}" = "$file" ] || [ "${file##*.}" = "dSYM" ]; }; then
        echo "Deleting $file"
        rm -rf "$file"
      fi
    done
    exit 0
  fi

  # check if file has a .c extension
  if [ "${file##*.}" != "c" ]; then
    echo "$file is not a .c file"
    continue
  fi

  # remove the .c extension
  filename="${file%.*}"

  # compile the .c file into an executable
  cc -Wall -Wextra -Werror -g "$file" -o "$filename"

  echo "Compiled $file into $filename"
done
