/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_doubletab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:05:12 by clesaffr          #+#    #+#             */
/*   Updated: 2022/07/29 16:10:00 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_doubletab(char **doubletab)
{
	int	i;
	int	total;

	if (!doubletab)
		return ;
	i = 0;
	total = ft_size_of_doubletab(doubletab);
	while (i < total)
	{
		free(doubletab[i]);
		i++;
	}
	free(doubletab);
}
