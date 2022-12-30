/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_items.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:38:24 by clesaffr          #+#    #+#             */
/*   Updated: 2022/12/30 15:23:16 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	items_are_valid(t_items *items)
{
	if (items->collect == 0 || items->persona != 1 || items->exit != 1)
		return (0);
	else
		return (1);
}

int	if_items_valid(t_items *items)
{
	if (items_are_valid(items))
		return (items->collect);
	else
	{
		ft_putstr("Items not valid\n");
		return (-1);
	}
}

int	finding_little_e(char **map)
{
	int	y;
	int	x;
	int	found;

	y = 0;
	x = 0;
	found = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'e')
				found = 1;
			x++;
		}
		x = 0;
		y++;
	}
	return (found);
}

void	setting_char_position(char c, char **map, int *x, int *y)
{
	int	persona;

	persona = 0;
	while (map[*y])
	{
		while (map[*y][*x])
		{
			if (map[*y][*x] == c)
			{
				persona = 1;
				break ;
			}
			*x += 1;
		}
		if (persona)
			break ;
		*x = 0;
		*y += 1;
	}
}
