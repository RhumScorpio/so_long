/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_items.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:38:24 by clesaffr          #+#    #+#             */
/*   Updated: 2022/12/23 13:36:44 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_items(t_items *items)
{
	printf("collectibles = %d\npersona = %d\nexit = %d\n",
		items->collect, items->persona, items->exit);
}

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
