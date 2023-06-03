# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 11:35:21 by yshimoma          #+#    #+#              #
#    Updated: 2023/06/03 21:07:58 by yshimoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = microshell
SRCS_DIR = ./src
SRCS = main.c tokenizer.c put_execve.c pipe.c cmd.c
vpath %.c ${SRCS_DIR}
OBJ_DIR	= ./obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEP_DIR	= ./dep
DEPS = $(addprefix $(DEP_DIR)/, $(SRCS:.c=.d))
LIBFT_DIR = ./libft
NAME_LIBFT = /libft.a
INCLUDE = ./header
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
READLINE = -L/Users/yshimoma/.brew/opt/readline/lib -I/Users/yshimoma/.brew/opt/readline/include -lreadline
# READLINE = -lreadline
RM = rm -rf

all: ${NAME}

# ${OBJS}: ${INCLUDE}/microshell.h

${NAME}: ${OBJS} ${DEPS}
	$(MAKE) bonus -C ${LIBFT_DIR}
	${CC} ${CFLAGS}  ${READLINE} -I${INCLUDE} ${LIBFT_DIR}${NAME_LIBFT} ${OBJS} -o $@

${OBJ_DIR}/%.o:%.c
	mkdir -p ${OBJ_DIR}
	${CC} -I${INCLUDE} -c $< -o $@

${DEP_DIR}/%.d:%.c
	mkdir -p ${DEP_DIR}
	${CC} -I${INCLUDE} -M $< > $@

clean:
	$(MAKE) clean -C ${LIBFT_DIR}
	${RM} ${OBJS} ${OBJ_DIR}
	${RM} ${DEPS} ${DEP_DIR}

fclean: clean
	${RM} ${NAME} ${NAME_LIBFT}

re: fclean all

-include ${DEPS}

.PHONY: all clean fclean re
