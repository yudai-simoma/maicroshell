# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 11:35:21 by yshimoma          #+#    #+#              #
#    Updated: 2023/05/21 12:51:45 by yshimoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = maicroshell
SRCS_DIR = ./src
SRCS = main.c
vpath %.c ${SRCS_DIR}
OBJ_DIR	= ./obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
LIBFT_DIR = ./libft
NAME_LIBFT = libft.a
INCLUDE = ./header
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

all: ${NAME}

${OBJS}: maicroshell.h

${NAME}: ${OBJS}
	$(MAKE) bonus -C ${LIBFT_DIR}
	${CC} -I${INCLUDE} ${NAME_LIBFT} ${OBJS} -o $@

${OBJ_DIR}/%.o:%.c
	mkdir -p ${OBJ_DIR}
	${CC} ${CFLAGS} -I${INCLUDE} -c $< -o $@

clean:
	$(MAKE) clean -C ${LIBFT_DIR}
	${RM} ${OBJS} ${OBJ_DIR}

fclean: clean
	${RM} ${NAME} ${NAME_LIBFT}

re: fclean all

.PHONY: all clean fclean re
