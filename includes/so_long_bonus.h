/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 11:43:05 by wjasmine          #+#    #+#             */
/*   Updated: 2022/04/28 11:13:44 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
# define SCALE 60
# define UP 13
# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define CROSS 15
# define ESCAPE 53
# define W 126
# define A 123
# define S 125
# define D 124

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
	unsigned int	player;
	unsigned int	collectible;
	unsigned int	exit;
	unsigned int	is_wall;
	unsigned int	moves;
	unsigned int 	patrol;
}	t_flags;

typedef	struct	s_map
{
	size_t			size_y;
	size_t			size_x;
	struct s_flags	flags;
	char			*field;
	void			*mlx;
	void			*mlx_win;
	size_t			player_field;
	int 			player_x;
	int 			player_y;
	void 			*img;
	size_t			patrol_field;
	int 			patrol_x;
	int				patrol_y;
}	t_map;

void	error(char *message);
void	ft_putstr_fd(char *s, int fd);
void	*ft_memset(void *block, int c, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
enum	e_errors	map_parser(int fd, t_map *map);
void	ft_start_mlx(t_map *map);
void	draw_map(t_map *map);
int		key_hook(int keycode, t_map *map);
void	my_xpm_to_image(int x, int y, const char *file, t_map *map);
int		ft_exit(t_map *map);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);
int		display_score(t_map *map);
int		animation(t_map *map);
void	activate_patrol(t_map *map);
void	ft_putchar_fd(char c, int fd);
void	patrol_moves(t_map *map);

#endif //SO_LONG_BONUS_H
