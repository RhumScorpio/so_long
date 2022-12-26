/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_reading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:35:44 by clesaffr          #+#    #+#             */
/*   Updated: 2022/12/26 00:22:06 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	pre_gnl_to_y(char *file_name)
{
	int		y;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	line = NULL;
	y = 0;
	while (get_next_line(fd, &line))
	{
		y++;
		free(line);
		line = NULL;
	}
	free(line);
	close(fd);
	return (y);
}

int	file_error(void)
{
	ft_putstr("File mapping is not correct\n");
	return (-1);
}

int	gnl_file(char *line, int fd, int y, t_items *items)
{
	int	gnl;
	int	x;
	int	error;
	int	i;

	gnl = get_next_line(fd, &line);
	x = gnl;
	i = 0;
	error = 0;
	while (gnl)
	{
		if ((i - y) == -1)
			i = -1;
		if (checkif_line_valid(i, &line, items) != x)
			error = -1;
		i++;
		gnl = get_next_line(fd, &line);
	}
	free(line);
	if (x < 3 || y < 3 || error < 0)
		return (file_error());
	else
		return (x);
}
