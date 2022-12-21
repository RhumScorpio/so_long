/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:36:53 by clesaffr          #+#    #+#             */
/*   Updated: 2022/12/21 19:10:55 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	the_line_is_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i] == '1')
		++i;
	return (i);
}

int	is_some_item(char c, t_items *items)
{
	if (c == 'C')
		return (items->collect++);
	else if (c == 'P')
		return (items->persona++);
	else if (c == 'E')
		return (items->exit++);
	else if (c == '1' || c == '0')
		return (1);
	else
		return (-1);
}

int	the_line_is_in(char *line, t_items *items)
{
	int	i;

	if (line[0] != '1')
		return (-1);
	i = 1;
	while (line[i] && is_some_item(line[i], items) != -1)
		++i;
	if (line[i - 1] != '1')
		return (-1);
	return (i);
}

int	checkif_line_valid(int i, char **line, t_items *items)
{
	int	x;

	x = 0;
	if (i == -1 || i == 0)
		x = the_line_is_wall(*line);
	else
		x = the_line_is_in(*line, items);
	free(*line);
	*line = NULL;
	return (x);
}
