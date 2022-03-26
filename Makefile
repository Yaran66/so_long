# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 15:24:34 by wjasmine          #+#    #+#              #
#   Updated: 2022/03/24 10:35:15 by wjasmine         ###   ########.fr       # #
#                                                                              #
# **************************************************************************** #


NAME		=	so_long

SRCS		=	so_long.c

#HEADER		=	so_long.h

OBJS		= 	${SRCS:%.c=%.o}

CC			= 	gcc
RM			= 	rm -f

OPTFLAGS 	= 	-O2 -w
CFLAGS		= 	-Wall -Wextra -Werror -Imlx
MLX			=	-L mlx -lmlx -framework OpenGL -framework AppKit


.PHONY:			all clean fclean re

all:			${NAME}

${NAME}:		${OBJS}
				make -s -C ./mlx
				${CC} ${OBJS} ${MLX} -o ${NAME}

%.o	:			%.c #${HEADER} Makefile
				${CC} ${CFLAGS} ${OPTFLAGS}	-c $< -o $@


clean:
				${RM} ${OBJS}
				make clean -C ./mlx

fclean:			clean
				${RM} ${NAME}
				make fclean -C ./mlx

re:				fclean all
				make re -C ./mlx
