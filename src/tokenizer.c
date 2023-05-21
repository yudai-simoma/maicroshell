/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:10:48 by yshimoma          #+#    #+#             */
/*   Updated: 2023/05/21 18:12:51 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

/*
 * tokenizerのmallocサイズを返す
 */
static size_t	_ft_word_size(char **argv)
{
	size_t	size_;

	size_ = 0;
	argv = NULL;
	return (size_);
}

/*
 * tokenizerを行う
 * 
 * TODO:splitしかしていないので、全ての実装が残っている
 */
char	**ft_tokenizer(int argc, char **argv)
{
	char	**word_;
	size_t	word_size_;

	argc = 0;
	word_size_ = _ft_word_size(argv);
	// word_ = (char **)malloc(sizeof(char *) * (word_size_ + 1));
	word_ = ft_split(argv[1], ' ');
	return (word_);
}
