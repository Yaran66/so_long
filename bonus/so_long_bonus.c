/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 11:42:37 by wjasmine          #+#    #+#             */
/*   Updated: 2022/04/20 20:56:58 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/so_long_bonus.h"
#include <stdlib.h>
#include "mlx/mlx.h"

void	ft_start_mlx(t_map *map)
{
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, map->size_x * SCALE, map->size_y *
	SCALE,
							 "so_long");
	draw_map(map);
	mlx_hook(map->mlx_win, 2, 0, key_hook, map);
//	mlx_mouse_hook(map->mlx_win, mouse_hook, &map);
	mlx_hook(map->mlx_win, 17, 0, ft_exit, 0); // TODO ft_close, это чтобы
	// программа останавливалвсь прои нажатии на крестик в окне
	mlx_loop(map->mlx);
}

static	enum	e_errors	ft_check_file_format(char *argv)
{
	if(!ft_strncmp(&argv[ft_strlen(argv) - 4], ".ber", 4))
		return(NO_ERROR);
	return (BAD_FILE_FORMAT);
}

void	ft_check_errors_type(enum e_errors err)
{
	if (!err)
		return ;
	ft_putstr_fd("Error\n", 2);
	if (err == BAD_ARGS)
		ft_putstr_fd("No or too many arguments (map file)\n",2);
	else if (err == BAD_DESCRIPTOR)
		ft_putstr_fd("Сould not open the file, bad fd\n",2);
	else if (err == BAD_FILE_FORMAT)
		ft_putstr_fd("Bad map file format, should be *.ber\n",2);
	else if (err == MAP_BAD_SHAPE)
		ft_putstr_fd("Map error: map must be rectangular\n",2);
	else if (err == MAP_BAD_SYMB)
		ft_putstr_fd("Map error: wrong symbols used\n",2);
	else if (err == MAP_BAD_PLAYER)
		ft_putstr_fd("Map error: no Player position or "
					 "more than one Player\n",2);
	else if (err == MAP_BAD_WALLS)
		ft_putstr_fd("Map error: map must be surrounded by walls\n",2);
	else if (err == MAP_BAD_EXIT)
		ft_putstr_fd("Map error: map must contain at least 1 exit\n",2);
	else if (err == MAP_BAD_COLLECTIBLE)
		ft_putstr_fd("Map error: map must contain at least 1 collectible\n",2);
	exit(err);
}

int main(int argc, char **argv)
{
	enum e_errors	err;
	int				fd;
	t_map			map;

	err = NO_ERROR;
	ft_memset(&map, 0, sizeof(map));
	if (argc == 2)
	{
		err = ft_check_file_format(argv[1]);
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			err = BAD_DESCRIPTOR;
		if(err == NO_ERROR)
		{
			err = map_parser(fd, &map); // TODO parser of the map
			close(fd);
		}
	}
	else
		err = BAD_ARGS;
	if (err != NO_ERROR)
		free(map.field);
	ft_check_errors_type(err);
	// TODO start game if no errors and map-parse is OK.
	ft_start_mlx(&map);
	return(err);//TODO what it suppose to return?
}
