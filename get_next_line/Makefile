# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 15:15:53 by yshimoma          #+#    #+#              #
#    Updated: 2023/05/28 12:39:06 by yshimoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c
# SRCS = get_next_line.c get_next_line_utils.c
OBJS = ${SRCS:.c=.o}
INCLUDE = ../header
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${ARFLAGS} ${NAME} ${OBJS}

.c.o:
	${CC} -I${INCLUDE} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re