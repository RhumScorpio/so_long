/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_a_valid_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:28:48 by clesaffr          #+#    #+#             */
/*   Updated: 2022/12/26 09:44:26 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

int	mapping_x(char **mapping)
{
	int	x;

	x = 0;
	while (mapping[0][x])
		x++;
	return(x);
}

int	mapping_y(char **mapping)
{
	int	y;

	y = 0;
	while (mapping[y])
		y++;
	return(y);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		printf("%s\n", map[i++]);
}

void	filling_copymap(char *map, char *mapping, int x)
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
		return(NULL);
	while (j < y)
	{
		map[j] = (char *)malloc(sizeof(char) * (x + 1));
		if (!map)
			return(NULL);
		filling_copymap(map[j], mapping[j + 1], x);
		j++;
	}
	print_map(map);
	return (map);
}

int	striking_every_valid_tiles(char **map)
{
	static t_items	items;
	int				y;
	int				x;

	// FINDING PERSONA POSITION
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
	printf("P = map[%d][%d]\n", y, x);
	// DOING LOOP
	return (items.collect);
}

int	check_path_to_win_game(char	**mapping, int collectibles)
{
	//check character position
	//check character position avance !1, if C = i+, if E = e+, or != P_precedent
	//faire (y, x + 1) puis (y - 1, x) puis (y, x - 1) puis (y + 1, x)
	//Stocker tout les P_precedent pour un check s'il sont bien complets pour la zone
	//Ou changer une valeur (P_passe) pour chaques pixels.
	//If !(i == collectibles) || !(e+) then return 0

	char **map_searched;
	int		total_collect;

	total_collect = 0;	
	printf("Collect total = %d\n", collectibles);
	map_searched = copy_map_for_path_search(mapping);
	total_collect = striking_every_valid_tiles(map_searched);
	free_mapping_variable(map_searched);
	if (collectibles == total_collect)
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	int	parsing_res;
	int	x;
	int	y;

	parsing_res = 0;
	if (ac != 2)
	{
		ft_putstr("Put one file please\n");
		return (0);
	}
	parsing_res = parsing(av[1], &x, &y);
	if (parsing_res)
		printf("PARSING IS GOOD\n");
	inspecting_map(parsing_res, av[1], x, y);
	return (0);
}
