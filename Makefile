# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 15:24:34 by wjasmine          #+#    #+#              #
#   Updated: 2022/04/25 21:15:34 by wjasmine         ###   ########.fr       # #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
NAME_B		= so_long_bonus

INCLUDES	= includes/
HEADER		= includes/so_long.h includes/get_next_line.h
HEADER_B	= includes/so_long_bonus.h includes/get_next_line.h

MLX_F		= font.c font.xcf mlx_init_loop.m \
              mlx_int.h mlx_int_str_to_wordtab.c mlx_mouse.m \
              mlx_new_image.m mlx_new_window.h mlx_new_window.m \
              mlx_opengl.h mlx_opengl.m mlx_png.c \
              mlx_png.h mlx_rgb.c mlx_shaders.c \
              mlx_xpm.c
MLX_DIR		= mlx/
MLX_H		= $(addprefix $(MLX_DIR), mlx.h)
MLX			= $(addprefix $(MLX_DIR), libmlx.a)
MLX_FLS		= $(addprefix $(MLX_DIR), $(MLX_F))

DIR			=
DIR_B		= bonus/
DIR_G		= gnl/
FILES		= draw_map.c \
				parser.c \
				play.c \
				so_long.c \
				so_long_utils.c
FILES_B		= draw_map_bonus.c \
              parser_bonus.c \
              play_bonus.c \
              so_long_bonus.c \
              so_long_utils_bonus.c \
              moves_bonus.c \
              animation_bonus.c \
              patrol_bonus.c
FILES_G		= get_next_line.c \
              get_next_line_utils.c


SRCS		= $(addprefix $(DIR), $(FILES)) $(addprefix $(DIR_G), $(FILES_G))
SRCS_B		= $(addprefix $(DIR_B), $(FILES_B)) $(addprefix $(DIR_G), $(FILES_G))

OBJS		= $(SRCS:%.c=%.o)
OBJS_B		= $(SRCS_B:%.c=%.o)

DS			= $(SRCS:%.c=%.d)
DS_B		= $(SRCS_B:%.c=%.d)

CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -MMD
MLX_FLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit

.PHONY: 	all clean fclean re bonus

all:		$(NAME)

$(MLX):		$(MLX_H) $(MLX_FLS)
			make -C $(MLX_DIR)

bonus:		$(NAME_B)

$(NAME_B): $(OBJS_B) $(MLX)
			$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS_B) $(MLX) -o $(NAME_B)

$(NAME):	$(OBJS) $(MLX)
			$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(MLX) -o $@

%.o:		%.c Makefile
			$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

-include	$(DS) $(DS_B)
#$(wildcard *.d)

clean:
			$(RM) $(OBJS) $(OBJS_B) $(DS) $(DS_B)
			make -C mlx clean

fclean:		clean
			$(RM) $(NAME) $(NAME_B)

re:			fclean all
