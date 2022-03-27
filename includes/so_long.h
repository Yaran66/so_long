/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 11:43:05 by wjasmine          #+#    #+#             */
/*   Updated: 2022/03/27 11:43:10 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "get_next_line.h"
# include "../mlx/mlx.h"
# include <fcntl.h>

# define SPACE '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

typedef	enum	e_errors
{
	NO_ERROR,
	BAD_ARGS,
	BAD_DESCRIPTOR,
	BAD_FILE_FORMAT,
	MAP_BAD_SHAPE,
	MAP_BAD_SYMB,
	MAP_BAD_WALLS,
	MAP_BAD_PLAYER,
	MAP_BAD_EXIT,
	MAP_BAD_COLLECTIBLE,
}	t_errors;

typedef	struct	s_flags
{
	char	player;
	char	collectible;
	char	exit;
	char	is_wall;
}	t_flags;

typedef	struct	s_map
{
	size_t			size_y;
	size_t			size_x;
	struct s_flags	flags;
	char			*field;
}	t_map;

void	error(char *message);
void	ft_putstr_fd(char *s, int fd);
void	*ft_memset(void *block, int c, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
enum	e_errors	map_parser(int fd, t_map *map);

#endif SO_LONG_H
