/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:	  */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:43:42 by wjasmine          #+#    #+#             */
/*   Updated: 2022/04/28 16:21:27 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

static int	size_of_nb(long int k)
{
	unsigned int	i;

	i = 0;
	while (k > 9)
	{
		i++;
		k = k / 10;
	}
	return (i + 1);
}

static char	*convert_nbr_to_str(char *str_nb, unsigned int i, long long k, \
	unsigned int sign)
{
	str_nb[i] = '\0';
	while (i-- && k > 9)
	{
		str_nb[i] = k % 10 + '0';
		k = k / 10;
	}
	str_nb[i--] = k % 10 + '0';
	if (sign)
		str_nb[i] = '-';
	return (str_nb);
}

char	*ft_itoa(int n)
{
	unsigned int	sign;
	unsigned int	i;
	char			*str_nb;
	long long		k;

	k = n;
	sign = 0;
	if (k < 0)
	{
		sign = 1;
		k = (((long long)(k)) * -1);
	}
	str_nb = (char *)malloc(sizeof(char) * (size_of_nb(k) + 1 + sign));
	if (str_nb == 0)
		return (0);
	i = (size_of_nb(k) + sign);
	str_nb = convert_nbr_to_str(str_nb, i, k, sign);
	return (str_nb);
}

int	display_score(t_map *map)
{
	char	*score;

	++map->flags.moves;
	score = ft_itoa(map->flags.moves);
	if (!score)
	{
		ft_putstr_fd("Error, score malloc\n", 2);
		ft_exit(map);
	}
	my_xpm_to_image(0, 0, "./images/mfaGrass.xpm", map);
	my_xpm_to_image(0, 0, "./images/Spikes.xpm", map);
	mlx_string_put(map->mlx, map->mlx_win, 10, 15, 0x00FFFFFF, "Moves: ");
	mlx_string_put(map->mlx, map->mlx_win, 50, 15, 0x00000000, score);
	free(score);
	return (0);
}
