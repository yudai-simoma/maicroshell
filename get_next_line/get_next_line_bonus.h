/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:54:40 by yshimoma          #+#    #+#             */
/*   Updated: 2023/05/29 18:30:08 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
size_t	ft_strlen_g(const char *s);
char	*ft_strdup_g(const char *src);
char	*ft_strjoin_g(char const *s1, char const *s2);
void	*ft_memcpy_g(void *dst, const void *src, size_t n);
void	*ft_memmove_g(void *dst, const void *src, size_t len);
char	*ft_strchr_g(const char *s, int c);

#endif
