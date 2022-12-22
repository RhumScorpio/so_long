/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:47:39 by clesaffr          #+#    #+#             */
/*   Updated: 2022/12/22 21:10:15 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

#define BUFFER_SIZE 1

static int	append_readtostr(int fd, t_all *a)
{
	char	buff[BUFFER_SIZE + 1];
	int		end;
	char	*tmp;

	end = read(fd, buff, BUFFER_SIZE);
	buff[end] = '\0';
	tmp = a->str;
	a->str = ft_gnlstrjoin(a->str, buff);
	if (tmp)
		free(tmp);
	return (end);
}

static int	line_copy(char **line, t_all *a, int backlashed)
{
	int	i;

	i = 0;
	while (a->str[i] && a->str[i] != '\n')
		i++;
	*line = ft_strndup(a->str, i);
	if (backlashed < 0)
		return (i);
	else
		return (i + 1);
}

static void	change_memorystring(t_all *a, int end)
{
	char	*tmp;

	tmp = a->str;
	if (tmp[end] != '\0' && end != 0)
		a->str = ft_strdup(a->str + end);
	else
		a->str = NULL;
	if (tmp)
		free(tmp);
}

static int	gnl_read(int fd, t_all *a, char **line)
{
	int		backlashed;
	int		end;
	int		foo;

	backlashed = 0;
	end = 1;
	while (end > 0)
	{
		end = append_readtostr(fd, a);
		backlashed = ft_strchr(a->str, '\n');
		if (backlashed >= 0)
			break ;
	}
	foo = line_copy(line, a, backlashed);
	change_memorystring(a, foo);
	if (backlashed == -1 && foo == 0)
		return (0);
	else
		return (foo);
}

int	get_next_line(int fd, char **line)
{
	static t_all	all;
	int				end;
	int				size;
	char			test[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, test, 0) == -1)
		return (-1);
	end = gnl_read(fd, &all, line);
	if (end == 0)
		return (0);
	size = ft_strlen(*line);
	return (size);
}
