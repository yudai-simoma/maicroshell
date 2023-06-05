/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:10:48 by yshimoma          #+#    #+#             */
/*   Updated: 2023/06/05 20:29:49 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

/*
 * tokenizerを行う
 * 
 * TODO:splitしかしていないので、全ての実装が残っている
 */
char	***ft_tokenizer(char *line)
{
	char	***word_;
	char	**str;
	int		i = 0;

	word_ = malloc(sizeof(char **) * 30);
	str = ft_split(line, '|');
	while (str[i] != NULL)
	{
		word_[i] = ft_split(str[i], ' ');
		i++;
	}
	word_[i] = NULL;
	return (word_);
}
