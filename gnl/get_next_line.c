/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjasmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:46:52 by wjasmine          #+#    #+#             */
/*   Updated: 2021/12/01 15:53:31 by wjasmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/get_next_line.h"

static	char	*cut_remain_if_n(char **remain, char *eol_ptr, char **line)
{
	char	*tmp;

	tmp = ft_strdup(*remain);
	eol_ptr = ft_strchr(tmp, '\n');
	eol_ptr++;
	*remain = ft_strcpy(*remain, eol_ptr);
	*eol_ptr = '\0';
	*line = ft_strdup(tmp);
	free(tmp);
	tmp = NULL;
	return (eol_ptr);
}

static	char	*check_remain(char *remain, char **line)
{
	char	*eol_ptr;

	eol_ptr = NULL;
	if (remain != NULL)
	{
		if (ft_strchr(remain, '\n'))
			eol_ptr = cut_remain_if_n (&remain, eol_ptr, line);
		else
		{
			*line = ft_strdup(remain);
			remain[0] = '\0';
		}
	}
	else
	{
		*line = (char *)malloc(sizeof(char) * (1));
		if (!*line)
			return (0);
		*line[0] = '\0';
	}
	return (eol_ptr);
}

static	char	*ft_strjoin_with_free(char *line, char *buf, char **remain)
{
	char	*tmp;
	char	*eol_ptr;

	tmp = line;
	if (ft_strchr(buf, '\n'))
	{
		eol_ptr = ft_strchr(buf, '\n');
		eol_ptr++;
		*remain = ft_strdup(eol_ptr);
		*eol_ptr = '\0';
	}
	line = ft_strjoin(line, buf);
	if (tmp)
		free(tmp);
	return (line);
}

static	void	free_null(char **str)
{
	free(*str);
	*str = NULL;
}

char	*get_next_line(int fd)
{
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int			byte_read;
	char		*eol_ptr;
	static char	*remain;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 10240 || (read(fd, buf, 0) != 0))
		return (NULL);
	eol_ptr = check_remain(remain, &line);
	if (!eol_ptr)
		free_null(&remain);
	byte_read = 1;
	while (!eol_ptr && byte_read)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read == -1)
			return (0);
		buf[byte_read] = '\0';
		eol_ptr = ft_strchr(buf, '\n');
		line = ft_strjoin_with_free(line, buf, &remain);
	}
	if (!ft_strlen(line) && !byte_read && !ft_strlen(remain))
		free_null(&line);
	return (line);
}
