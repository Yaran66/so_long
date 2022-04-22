# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 15:24:34 by wjasmine          #+#    #+#              #
#   Updated: 2022/04/21 22:17:55 by wjasmine         ###   ########.fr       # #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
NAME_B		=	so_long_bonus

SRCS		=	${SRC} ${SRC_GNL}
SRCS_B		=	${SRC_B} ${SRC_GNL_B}

SRC			=	so_long.c so_long_utils.c parser.c draw_map.c play.c
GNL			= 	get_next_line.c get_next_line_utils.c
SRC_GNL		= 	$(addprefix gnl/, $(GNL))
BONUS		=	so_long_bonus.c	so_long_utils-bonus.c parser_bonus.c draw_map_bonus.c play_bonus.c
SRC_B		=	$(addprefix ./bonus, $(BONUS))
SRC_GNL_B	= 	$(addprefix ./gnl, $(GNL))

INCLUDES	=	includes
D_FILES		=	$(addprefix $(SCRS),$(patsubst %.c,%.d,$(SRCS)))
D_FILES_B	=	$(addprefix $(SRCS_B),$(patsubst %.c,%.d,$(SRCS_B)))

OBJS		= 	${SRCS:%.c=%.o}
OBJS_B		= 	${SRCS_B:%.c=%.o}
T_FILE		=	.bonus

CC			= 	gcc
RM			= 	rm -f

OPTFLAGS 	= 	-O2
CFLAGS		= 	-Wall -Wextra -Werror -Imlx
MLX			=	-Lmlx -lmlx -framework OpenGL -framework AppKit


.PHONY:			all clean fclean re

all:			${NAME}

bonus:
				make NAME="$(NAME_B)" \
				OBJS="$(OBJS_B)"	all

${NAME}:		${OBJS}
				make -s -C ./mlx
				${CC} ${OBJS} ${MLX} -o ${NAME}

%.o	:			%.c ${INCLUDES} Makefile
				${CC} ${CFLAGS} ${OPTFLAGS}	-I ${INCLUDES} -c $< -o $@ -MMD

#bonus:			${T_FILE}

#${T_FILE}:		${OBJS_B}
#				make -s -C ./mlx
#				${CC} ${OBJS_B} ${MLX} -o ${NAME_B}
#				@touch ${T_FILE}

-include		$(D_FILES)
-include		$(D_FILES_B)

clean:
				${RM} ${OBJS} ${OBJS_B}
				make clean -C ./mlx
				$(RM) $(D_FILES)
				$(RM) $(D_FILES_B)

fclean:			clean
				${RM} ${NAME} ${NAME_B}
				make clean -C ./mlx

re:				fclean all
				make re -C ./mlx
