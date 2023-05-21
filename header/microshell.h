/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:49:46 by yshimoma          #+#    #+#             */
/*   Updated: 2023/05/21 21:16:57 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H
# include <string.h> // strcmp
# include <unistd.h> // write, close, dup, dup2, close, execve, chdir and fork
# include <sys/wait.h> // waitpid
# include <stdlib.h> //malloc, free
# include <signal.h> //kill, signal
# include <stdio.h>
# include "libft.h"

#define RED_COLOR "\033[31m"
#define RESET_COLOR "\033[0m"

//put_execve.c
void	ft_put_execve(char **args, char **envp);
//tokenizer.c
char	**ft_tokenizer(int argc, char **argv);

#endif