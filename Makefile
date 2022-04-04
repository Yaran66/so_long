# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 15:24:34 by wjasmine          #+#    #+#              #
#   Updated: 2022/04/02 12:53:43 by wjasmine         ###   ########.fr       # #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRCS		=	${SRC} ${SRC_GNL}

SRC			=	so_long.c so_long_utils.c parser.c err_cln.c
GNL			= 	get_next_line.c get_next_line_utils.c
SRC_GNL		= 	$(addprefix gnl/, $(GNL))
INCLUDES	=	includes
D_FILES		=	$(addprefix $(SCRS),$(patsubst %.c,%.d,$(SRCS)))

OBJS		= 	${SRCS:%.c=%.o}

CC			= 	gcc
RM			= 	rm -f

OPTFLAGS 	= 	-O2 -w
CFLAGS		= 	-Wall -Wextra -Werror #-Imlx
#MLX			=	-Lmlx -lmlx -framework OpenGL -framework AppKit


.PHONY:			all clean fclean re

all:			${NAME}

${NAME}:		${OBJS}
				#make -s -C ./mlx
				${CC} ${OBJS} ${MLX} -o ${NAME}

%.o	:			%.c ${INCLUDES} Makefile
				${CC} ${CFLAGS} ${OPTFLAGS}	-I ${INCLUDES} -c $< -o $@ -MMD

-include		$(D_FILES)

clean:
				${RM} ${OBJS}
				#make clean -C ./mlx
				$(RM) $(D_FILES)

fclean:			clean
				${RM} ${NAME}
				#make clean -C ./mlx

re:				fclean all
				#make re -C ./mlx