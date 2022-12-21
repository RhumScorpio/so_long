/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:33:53 by clesaffr          #+#    #+#             */
/*   Updated: 2022/12/21 19:38:42 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	try_opening(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Opening failed, does file exist?\n");
		return (0);
	}
	close(fd);
	return (1);
}

int	check_file_extension(char *file_name)
{
	int	i;

	i = ft_strlen(file_name);
	if (i < 5)
	{
		ft_putstr("File name is too short\n");
		return (0);
	}
	else if (file_name[i - 4] == '.' && file_name[i - 3] == 'b'\
		&& file_name[i - 2] == 'e' && file_name[i - 1] == 'r')
		return (try_opening(file_name));
	else
	{
		ft_putstr("File does not end with .ber\n");
		return (0);
	}
}

//Where should I store map info?
//When do I create the data struct?
//I should do a first gnl for error handling THEN do a malloc with the data

int	check_file_lines(char *file_name)
{
	static t_items	items;
	int				fd;
	int				y;
	int				x;
	char			*line;

	line = NULL;
	y = pre_gnl_to_y(file_name);
	fd = open(file_name, O_RDONLY);
	x = gnl_file(line, fd, y, &items);
	close(fd);
	if (x > 0)
		return (if_items_valid(items));
	else
		return (-1);
}

int	parsing(char *file_name)
{
	if (!file_name)
		return (0);
	if (check_file_extension(file_name))
	{
		if (check_file_lines(file_name) > 0)
			return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	parsing_res;

	parsing_res = 0;
	if (ac != 2)
	{
		ft_putstr("Put one file please\n");
		return (0);
	}
	parsing_res = parsing(av[1]);
	if (parsing_res)
		printf("PARSING IS GOOD\n");
	return (0);
}
