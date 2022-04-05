/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:51:35 by wjasmine          #+#    #+#             */
/*   Updated: 2022/04/05 16:59:19 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/get_next_line.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == ((char)c))
		{
			return (((char *)s) + i);
		}
		i++;
	}
	if (c == 0)
	{
		return (((char *)s) + i);
	}
	return (0);
}

size_t	ft_strlen(const char *ch)
{
	size_t	i;

	i = 0;
	while (ch && ch[i] != '\0')
		++i;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	ptr = malloc (sizeof(*s1) * (ft_strlen(s1) + 1));
	i = 0;
	if (ptr == 0)
	{
		return (0);
	}
	while (s1[i] != 0)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;

//	if (s1 == 0 || s2 == 0)
	if (s2 == 0)
		return (0);
	newstr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (newstr == 0)
		return (0);
	i = 0;
	while (s1 && *s1)
	{
		newstr[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		newstr[i] = *s2;
		s2++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
