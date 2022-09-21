/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:56:10 by clesaffr          #+#    #+#             */
/*   Updated: 2021/11/17 20:23:48 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_int(int n, char *str, int size)
{
	int				i;
	unsigned int	nbr;

	if (!str)
		return (NULL);
	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	i = size - 1;
	str[size] = '\0';
	while (i >= 0)
	{
		if (n < 0 && i == 0)
		{
			str[0] = '-';
			return (str);
		}
		str[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				size;
	unsigned int	nbr;

	size = 1;
	if (n < 0)
	{
		size++;
		nbr = -n;
	}
	else
		nbr = n;
	while (nbr >= 10)
	{
		size++;
		nbr /= 10;
	}
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	return (ft_itoa_int(n, str, size));
}
