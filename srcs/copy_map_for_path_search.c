/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map_for_path_search.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:02:21 by clesaffr          #+#    #+#             */
/*   Updated: 2022/12/30 00:48:28 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	mapping_x(char **mapping)
{
	int	x;

	x = 0;
	while (mapping[0][x])
		x++;
	return (x);
}

int	mapping_y(char **mapping)
{
	int	y;

	y = 0;
	while (mapping[y])
		y++;
	return (y);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		printf("%s\n", map[i++]);
}

static void	filling_copymap(char *map, char *mapping, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		map[i] = mapping[i + 1];
		i++;
	}
	map[i] = '\0';
}

char	**copy_map_for_path_search(char **mapping)
{
	int		x;
	int		y;
	int		j;
	char	**map;

	x = mapping_x(mapping) - 2;
	y = mapping_y(mapping) - 2;
	j = 0;
	map = malloc_mapping(y);
	if (!map)
		return (NULL);
	while (j < y)
	{
		map[j] = (char *)malloc(sizeof(char) * (x + 1));
		if (!map)
		{
			free_mapping_variable(map);
			return (NULL);
		}
		filling_copymap(map[j], mapping[j + 1], x);
		j++;
	}
	return (map);
}
