/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_a_valid_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:28:48 by clesaffr          #+#    #+#             */
/*   Updated: 2022/12/23 20:42:12 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"
//Questions apposee
//Quel est le fonctionnement du systeme et pourquoi les neurones du cerveau
// rentrent dans un systeme semblable au mycelium. Decrire le mycelium en tant que mecanisme biologique.
//Pourquoi la societe, en structure de controle des humains, est une sorte de mycelium au final?
/*
int	position_start(char **mapping, int *i, int *j)
{
	while (mapping[i])
	{
		while (mapping[i][j])
		{
			if(mapping[i][j] == 'P')
				return (0);
			*j++;
		}
		*i++;
	}
	return (0);
}

void	loop_till_filled(char **mapping, int collectibles)
{
	int	clt_total;
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	clt_total = 0;
	//position_start(mapping, &i, &j);
	//While not filled
	if (valid_fill(mapping[i][j]))
	{
		
	}

}
*/

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

char	**copy_map_for_path_search(char **mapping)
{
	int		x;
	int		i;
	int		y;
	int		j;
	char	**map;

	x = mapping_x(mapping) - 1;
	y = mapping_y(mapping) - 2;
	i = 0;
	j = 0;
	map = malloc_mapping(y);
	if (!map)
		return(NULL);
	while (j <= y)
	{
		map[j] = (char *)malloc(sizeof(char) * x);
		if (!map)
			return(NULL);
		while (i < x)
		{
			printf("map[%d][%d] = mapping[%d][%d]\n", j, i, j+1, i+1);
			map[j][i] = mapping[j + 1][i + 1];
			i++;
		}
		map[j][i] = '\0';
		printf("&& %s\n", map[j]);
		j++;
	}
	print_map(map);
	return (map);
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

	printf("Collect total = %d\n", collectibles);
	map_searched = copy_map_for_path_search(mapping);
	free_mapping_variable(map_searched);
//	loop_till_filled(mapping, collectibles);
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
