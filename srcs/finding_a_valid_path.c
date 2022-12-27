/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_a_valid_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:28:48 by clesaffr          #+#    #+#             */
/*   Updated: 2022/12/27 01:08:14 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

static int recursive_tile_flooding(char **map, int	x, int	y)
{
	int	born_y;
	int	born_x;
	static int	total;

	born_y = mapping_y(map);
	born_x = ft_strlen(map[0]);
	if ((born_x > x && x >= 0) && (born_y > y && y >= 0))
	{
		if (map[y][x] == 'C')
			total++;
		if(map[y][x] == 'E' || map[y][x] == 'e')
			map[y][x] = 'e';
		else
			map[y][x] = '1';
		if ((x + 1 < born_x) && map[y][x + 1] != '1' && map[y][x])
			recursive_tile_flooding(map, x + 1, y);
		if ((y - 1 >= 0) && map[y - 1][x] != '1' && map[y][x])
			recursive_tile_flooding(map, x, y - 1);
		if ((x - 1 >= 0) && map[y][x - 1] != '1' && map[y][x])
			recursive_tile_flooding(map, x - 1, y);
		if ((y + 1 < born_y) && map[y + 1][x] != '1' && map[y][x])
			recursive_tile_flooding(map, x, y + 1);
	}
	return (total);
}

static int	finding_little_e(char **map)
{
	int				y;
	int				x;
	int			found;

	y = 0;
	x = 0;
	found = 0;
	while (map[y])
	{
		while(map[y][x])
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

static int	striking_every_valid_tiles(char **map)
{
	static t_items	items;
	int				y;
	int				x;

	y = 0;
	x = 0;
	while (map[y])
	{
		while(map[y][x])
		{
			if (map[y][x] == 'P')
			{
				items.persona = 1;
				break ;
			}
			x++;
		}
		if (items.persona)
			break ;
		x = 0;
		y++;
	}
	items.collect = recursive_tile_flooding(map, x, y);
	if (!finding_little_e(map))
		items.collect = -1;
	return (items.collect);
}

int	check_path_to_win_game(char	**mapping, int collectibles)
{
	char	**map;
	int		total_collect;

	map = copy_map_for_path_search(mapping);
	if (!map)
		return (0);
	total_collect = striking_every_valid_tiles(map);
	free_mapping_variable(map);
	if (collectibles == total_collect)
		return (1);
	else
	{
		ft_putstr("There's no path that wins\n");
		return (0);
	}
}
