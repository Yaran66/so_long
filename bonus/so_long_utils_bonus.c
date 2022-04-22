/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:08:14 by wjasmine          #+#    #+#             */
/*   Updated: 2022/04/20 22:21:43 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/so_long_bonus.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s != 0 && fd >= 0)
		write (fd, s, ft_strlen(s));
}

void	*ft_memset(void *block, int c, size_t size)
{
	while (size--)
	{
		((unsigned char *)block)[size] = (unsigned char)c;
	}
	return (block);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n)
	{
		if (*s1 != *s2)
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void ft_putnbr_fd(int n, int fd)
{
	long i;

	i = n;
	if (i < 0)
	{
		ft_putchar_fd ('-', fd);
		i = i * (-1);
	}
	if (i < 10)
		ft_putchar_fd ((char)('0' + i), fd);
	if (i > 9)
	{
		ft_putnbr_fd (i / 10, fd);
		ft_putchar_fd ((char)('0' + (i % 10)), fd);
	}
}