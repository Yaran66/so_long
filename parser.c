/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:15:01 by wjasmine          #+#    #+#             */
/*   Updated: 2022/03/27 14:15:05 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/so_long.h"

enum e_errors	ft_check_map(t_map *map, char *str)
{

}

static void ft_check_flags(t_map *map, enum e_errors *error)

enum e_errors	map_parser(int fd, t_map *map)
{
	char			*str;
	char			*tmp;
	enum e_errors	err;

	err = NO_ERROR;
	str = get_next_line(fd);
	map->size_x = ft_strlen(str);
	if(str)
		err = ft_check_map(map, str) // TODO check the map for correct symbols,
				// size, ..
	if (!error && !map->flags.is_wall) // TODO BAD_WALLS, adelina, ХЗ пока зачем
		error = MAP_BAD_WALLS;
	while (err == NO_ERROR && str)
	{
		tmp = map->field;
		map->field = ft_strjoin(tmp, str);
		free(tmp);
		free(str);
		++map->size_y; // count y (width)
		str = get_next_line(fd);
		err = ft_check_map()
	}
	free(str);
	ft_check_flags(map, &err) // TODO check flags, in case if flags is 0
	// (missing
	// wall, exit, player (or too many players)
	return (err);
}
