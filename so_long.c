/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 11:42:37 by wjasmine          #+#    #+#             */
/*   Updated: 2022/05/02 19:55:01 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/so_long.h"

void	ft_start_mlx(t_map *map)
{
	map->mlx = mlx_init();
	if (map->mlx == 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("MLX error", 2);
		ft_exit(map);
	}
	map->mlx_win = mlx_new_window(map->mlx, map->size_x * SCALE, \
		map->size_y * SCALE, "so_long");
	if (map->mlx_win == 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("MLX error", 2);
		ft_exit(map);
	}
	draw_map(map);
	mlx_hook(map->mlx_win, 2, 0, key_hook, map);
	mlx_hook(map->mlx_win, 17, 1L << 17, ft_exit, map);
	mlx_loop(map->mlx);
}

static	enum	e_errors	ft_check_file_format(char *argv)
{
	if (!ft_strncmp(&argv[ft_strlen(argv) - 4], ".ber", 4))
		return (NO_ERROR);
	return (BAD_FILE_FORMAT);
}

void	ft_check_errors_type(enum e_errors err)
{
	if (!err)
		return ;
	ft_putstr_fd("Error\n", 2);
	if (err == BAD_ARGS)
		ft_putstr_fd("No or too many arguments (map file)\n", 2);
	else if (err == BAD_DESCRIPTOR)
		ft_putstr_fd("Сould not open the file, bad fd\n", 2);
	else if (err == BAD_FILE_FORMAT)
		ft_putstr_fd("Bad map file format, should be *.ber\n", 2);
	else if (err == MAP_BAD_SHAPE)
		ft_putstr_fd("Map error: map must be rectangular\n", 2);
	else if (err == MAP_BAD_SYMB)
		ft_putstr_fd("Map error: wrong symbols used\n", 2);
	else if (err == MAP_BAD_PLAYER)
		ft_putstr_fd("Map error: no Player or more than 1 Player\n", 2);
	else if (err == MAP_BAD_WALLS)
		ft_putstr_fd("Map error: map must be surrounded by walls\n", 2);
	else if (err == MAP_BAD_EXIT)
		ft_putstr_fd("Map error: map must contain at least 1 exit\n", 2);
	else if (err == MAP_BAD_COLLECTIBLE)
		ft_putstr_fd("Map error: map must contain at least 1 collectible\n", 2);
	exit(err);
}

int	main(int argc, char **argv)
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
		if (err == NO_ERROR)
		{
			err = map_parser(fd, &map);
			close(fd);
		}
	}
	else
		err = BAD_ARGS;
	if (err != NO_ERROR)
		free(map.field);
	ft_check_errors_type(err);
	ft_start_mlx(&map);
	return (err);
}
