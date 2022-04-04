/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:44:57 by wjasmine          #+#    #+#             */
/*   Updated: 2022/04/01 12:33:26 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	lst_cleaner(t_push_swap *ps)
{
	free(ps->arr);
	ft_lstclear(&ps->a, free);
	ft_lstclear(&ps->b, free);
}

void	print_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr_fd(arr[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != 0 && fd >= 0)
		write (fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(int n, int fd)
{
	long	i;

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

void	print_lst(t_map *lst)
{
	while (lst)
	{
		ft_putnbr_fd(*(int *)lst->content, 1);
		ft_putchar_fd('\n', 1);
		lst = lst->next;
	}
}