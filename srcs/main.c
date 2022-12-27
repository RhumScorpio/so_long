/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:07:14 by clesaffr          #+#    #+#             */
/*   Updated: 2022/12/27 01:30:56 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	if (inspecting_map(parsing_res, av[1], x, y))
		printf("GOOD\n");
		// LANCER LA PARTIE GRAPHIQUE
	return (0);
}
