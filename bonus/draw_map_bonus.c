/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:15:01 by wjasmine          #+#    #+#             */
/*   Updated: 2022/04/23 12:31:32 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	my_xpm_to_image(int x, int y, const char *file, t_map *map)
{
	int		img_width;
	int		img_height;

	map->img = mlx_xpm_file_to_image(map->mlx, (char *)file, &img_width, \
		&img_height);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img, x, y);
}

void	post_image(int x, int y, char c, t_map *map)
{
	my_xpm_to_image(x, y, "./images/mfaGrass.xpm", map);
	if (c == '1')
		my_xpm_to_image(x, y, "./images/Spikes.xpm", map);
	if (c == 'P')
		my_xpm_to_image(x, y, "./images/Knight.xpm", map);
	if (c == 'C')
		my_xpm_to_image(x, y, "./images/Heart.xpm", map);
	if (c == 'E')
		my_xpm_to_image(x, y, "./images/Princess.xpm", map);
}

void	draw_map(t_map *map)
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
			if (map->field[k] == 'P')
			{
				map->player_field = k;
				map->player_x = j;
				map->player_y = i;
			}
			post_image(j * SCALE, i * SCALE, map->field[k++], map);
			++j;
		}
		++i;
		++k;
	}
}
