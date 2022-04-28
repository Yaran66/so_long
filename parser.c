/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:15:01 by wjasmine          #+#    #+#             */
/*   Updated: 2022/04/22 23:10:56 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/so_long.h"

static int	ft_is_correct_symbol(char c)
{
	if (c == PLAYER || c == WALL || c == EXIT || c == COLLECTIBLE
		|| c == SPACE)
		return (1);
	return (0);
}

static void	rise_flag(t_map *map, char c)
{
	if (map->flags.is_wall && c != WALL)
		map->flags.is_wall = 0;
	if (c == PLAYER)
		++map->flags.player;
	if (c == COLLECTIBLE)
		++map->flags.collectible;
	if (c == EXIT)
		++map->flags.exit;
}

static enum e_errors	ft_check_map(t_map *map, char *str)
{
	size_t			i;
	enum e_errors	err;

	i = 0;
	err = NO_ERROR;
	if (!str)
		return (err);
	map->flags.is_wall = 1;
	if (str[i++] != WALL)
		err = MAP_BAD_WALLS;
	while (err == NO_ERROR && str[i] != '\n' && str[i] != '\0')
	{
		rise_flag(map, str[i]);
		if (!ft_is_correct_symbol(str[i]))
			err = MAP_BAD_SYMB;
		++i;
	}
	if (i != map->size_x && err != MAP_BAD_SYMB)
		err = MAP_BAD_SHAPE;
	else if (str[i - 1] != WALL && err != MAP_BAD_SYMB)
		err = MAP_BAD_WALLS;
	return (err);
}

static void	ft_check_flags(t_map *map, enum e_errors *error)
{
	if (map->flags.player != 1 && *error == NO_ERROR)
		*error = MAP_BAD_PLAYER;
	if (!map->flags.collectible && *error == NO_ERROR)
		*error = MAP_BAD_COLLECTIBLE;
	if (!map->flags.exit && *error == NO_ERROR)
		*error = MAP_BAD_EXIT;
	if (!map->flags.is_wall && *error == NO_ERROR)
		*error = MAP_BAD_WALLS;
}

enum e_errors	map_parser(int fd, t_map *map)
{
	char			*str;
	char			*tmp;
	enum e_errors	err;

	err = NO_ERROR;
	str = get_next_line(fd);
	map->size_x = (ft_strlen(str) - 1);
	if (str)
		err = ft_check_map(map, str);
	if (err == NO_ERROR && !map->flags.is_wall)
		err = MAP_BAD_WALLS;
	while (err == NO_ERROR && str)
	{
		tmp = map->field;
		map->field = ft_strjoin(tmp, str);
		free(tmp);
		free(str);
		++map->size_y;
		str = get_next_line(fd);
		err = ft_check_map(map, str);
	}
	free(str);
	ft_check_flags(map, &err);
	return (err);
}
