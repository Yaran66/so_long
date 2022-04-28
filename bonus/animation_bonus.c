/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:15:01 by wjasmine          #+#    #+#             */
/*   Updated: 2022/04/28 16:17:29 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

static void	player_animation(t_map	*map)
{
	static int	time = 0;

	if (time == 1500)
		my_xpm_to_image(map->player_x * SCALE, map->player_y * SCALE, \
			"./images/Knight.xpm", map);
	else if (time == 3000)
	{
		my_xpm_to_image(map->player_x * SCALE, map->player_y * SCALE, \
			"./images/mfaGrass.xpm", map);
		my_xpm_to_image(map->player_x * SCALE, map->player_y * SCALE, \
			"./images/Ghost.xpm", map);
		time = 0;
	}
	time++;
}

static void	patrol_animation(t_map *map)
{
	static int	time = 0;

	if (time == 1500)
		my_xpm_to_image(map->patrol_x * SCALE, map->patrol_y * SCALE, \
			"./images/Oldman.xpm", map);
	else if (time == 3000)
		my_xpm_to_image(map->patrol_x * SCALE, map->patrol_y * SCALE, \
			"./images/Vampire.xpm", map);
	else if (time == 4500)
	{
		my_xpm_to_image(map->patrol_x * SCALE, map->patrol_y * SCALE, \
			"./images/mfaGrass.xpm", map);
		my_xpm_to_image(map->patrol_x * SCALE, map->patrol_y * SCALE, \
			"./images/Slime.xpm", map);
		time = 0;
	}
	time++;
}

int	animation(t_map *map)
{
	player_animation(map);
	patrol_animation(map);
	patrol_moves(map);
	if (map->player_x == map->patrol_x && map->player_y == map->patrol_y)
	{
		ft_putstr_fd("Patrol catch you! Game over!\n", 2);
		ft_exit(map);
	}
	return (0);
}
