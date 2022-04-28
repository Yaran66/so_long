/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:15:01 by wjasmine          #+#    #+#             */
/*   Updated: 2022/04/28 16:54:00 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

static void	patrol_path(t_map *map, int x, int y)
{
	my_xpm_to_image(x * SCALE, y * SCALE, "./images/mfaGrass.xpm", map);
	if (map->field[map->patrol_field] == 'C')
		my_xpm_to_image(x * SCALE, y * SCALE, "./images/Heart.xpm", map);
	else if (map->field[map->patrol_field] == 'E')
		my_xpm_to_image(x * SCALE, y * SCALE, "./images/Princess.xpm", map);
}

static void	patrol_do_move(t_map *map, size_t i, int x, int y)
{
	char	cell;

	cell = map->field[i];
	if (cell == '1' && map->flags.patrol == 1)
	{
		map->flags.patrol = 0;
		return ;
	}
	else if (cell == '1' && map->flags.patrol == 0)
	{
		map->flags.patrol = 1;
		return ;
	}
	else if (cell == '0' || cell == 'P' || cell == 'E' || cell == 'C')
		patrol_path(map, map->patrol_x, map->patrol_y);
	map->patrol_x = x;
	map->patrol_y = y;
	map->patrol_field = i;
}

void	patrol_moves(t_map *map)
{
	static int	time = 0;

	if (time == 4500 && map->flags.patrol == 1)
	{
		patrol_do_move(map, map->patrol_field + map->size_x + 1, \
			map->patrol_x, map->patrol_y + 1);
		time = 0;
	}
	if (time == 4500 && map->flags.patrol == 0)
	{
		patrol_do_move(map, map->patrol_field - map->size_x - 1, \
			map->patrol_x, map->patrol_y - 1);
		time = 0;
	}
	++time;
}

static void	patrol_posn(t_map *map, int j, int i, int k)
{
	map->patrol_x = j;
	map->patrol_y = i;
	map->flags.patrol = 1;
	map->patrol_field = k;
}

void	activate_patrol(t_map *map)
{
	size_t	i;
	size_t	j;
	int		k;

	i = 0;
	k = 0;
	while (i < map->size_y)
	{
		j = 0;
		while (j < map->size_x)
		{
			if (map->field[k] == '0' && (map->field[k + map->size_x + 1] == '0'
					|| map->field[k + map->size_x + 1] == 'C'))
			{
				patrol_posn(map, j, i, k);
				return ;
			}
			++j;
			++k;
		}
		++i;
		++k;
	}
}
