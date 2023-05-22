/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:10:48 by yshimoma          #+#    #+#             */
/*   Updated: 2023/05/22 20:05:43 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

/*
 * tokenizerを行う
 * 
 * TODO:splitしかしていないので、全ての実装が残っている
 */
char	***ft_tokenizer(int argc, char **argv)
{
	char	***word_;
	char	**str;
	int		i = 0;

	argc = 0;
	word_ = malloc(sizeof(char **) * 30);
	str = ft_split(argv[1], '|');
	while (str[i] != NULL)
	{
		word_[i] = ft_split(str[i], ' ');
		i++;
	}
	word_[i] = NULL;
	return (word_);
}
