/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 09:32:34 by clesaffr          #+#    #+#             */
/*   Updated: 2020/02/25 09:32:34 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ucdst;
	unsigned char	*ucsrc;

	i = 0;
	ucdst = (unsigned char *)dst;
	ucsrc = (unsigned char *)src;
	while (i < n)
	{
		ucdst[i] = ucsrc[i];
		if (ucsrc[i] == (unsigned char)c)
			return ((void *)&ucdst[i + 1]);
		i++;
	}
	return (0);
}
