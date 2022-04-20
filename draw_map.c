//
// Created by Aleksey Tvorogov on 16.04.2022.
//
#include "includes/so_long.h"

void my_xpm_to_image(int x, int y, const char *file, t_map *map)
{
	int		img_width;
	int		img_height;

	map->img = mlx_xpm_file_to_image(map->mlx, (char *)file, &img_width,
								&img_height);
	// img_width img_height ни на что не влияют ХЗ почему так
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img, x, y);
}

void	post_image(int x, int y, char c, t_map *map)
{
	my_xpm_to_image(x, y, "./images/mfaGrass.xpm", map);
	if(c == '1')
		my_xpm_to_image(x, y, "./images/Spikes.xpm", map);
	if(c == 'P')
		my_xpm_to_image(x, y, "./images/Knight.xpm", map);
	if(c == 'C')
		my_xpm_to_image(x, y, "./images/Heart.xpm", map);
	if(c == 'E')
		my_xpm_to_image(x, y, "./images/Princess.xpm", map);
}


void	draw_map(t_map *map)
{
	size_t i;
	size_t j;
	int k;

	i = 0;
	k = 0;
	while (i < map->size_y)
	{
		j = 0;
		while (j < map->size_x)
		{
			if(map->field[k] == 'P')
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
