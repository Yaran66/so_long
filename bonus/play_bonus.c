/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:15:01 by wjasmine          #+#    #+#             */
/*   Updated: 2022/04/24 17:59:36 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

int	ft_exit(t_map *map)
{
	free(map->field);
	mlx_destroy_image(map->mlx, map->img);
	mlx_clear_window(map->mlx, map->mlx_win);
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit (0);
}

void	end_game(t_map *map)
{
	ft_putnbr_fd(map->flags.moves, 2);
	ft_putstr_fd(" moves You did to WIN!\n", 2);
	ft_exit(map);
}

static void	collect_collectable(t_map *map, int i, int x, int y)
{
	my_xpm_to_image(map->player_x * SCALE, map->player_y * SCALE, \
			"./images/mfaGrass.xpm", map);
	my_xpm_to_image(x * SCALE, y * SCALE, "./images/Knight.xpm", map);
	map->field[i] = '0';
	--map->flags.collectible;
}

static void	my_move(t_map *map, size_t i, int x, int y)
{
	char	cell;

	cell = map->field[i];
	if (cell == 'E' && map->flags.collectible == 0)
		end_game(map);
	if (cell == '1' || (cell == 'E' && map->flags.collectible > 0))
		return ;
	else if (cell == '0' || cell == 'P')
	{
		my_xpm_to_image(map->player_x * SCALE, map->player_y * SCALE, \
			"./images/mfaGrass.xpm", map);
		my_xpm_to_image(x * SCALE, y * SCALE, "./images/Knight.xpm", map);
	}
	else if (cell == 'C')
	{
		collect_collectable(map, i, x, y);
	}
	map->player_x = x;
	map->player_y = y;
	map->player_field = i;
	display_score(map);
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == RIGHT || keycode == D)
		my_move(map, map->player_field + 1, map->player_x + 1, map->player_y);
	else if (keycode == LEFT || keycode == A)
		my_move(map, map->player_field - 1, map->player_x - 1, map->player_y);
	else if (keycode == UP || keycode == W)
		my_move(map, map->player_field - map->size_x - 1, map->player_x, \
			map->player_y - 1);
	else if (keycode == DOWN || keycode == S)
		my_move(map, map->player_field + map->size_x + 1, map->player_x, \
			map->player_y + 1);
	else if (keycode == ESCAPE)
		ft_exit(map);
	return (0);
}
