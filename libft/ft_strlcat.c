/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 11:30:26 by clesaffr          #+#    #+#             */
/*   Updated: 2020/02/26 16:58:35 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			i;
	size_t			j;
	unsigned int	k;

	i = 0;
	while (*(dest + i) != '\0')
		++i;
	k = 0;
	while (*(src + k) != '\0')
		++k;
	j = 0;
	while (*(src + j) != '\0' && (i + j + 1) < size)
	{
		*(dest + i + j) = *(src + j);
		++j;
	}
	*(dest + i + j) = '\0';
	if (size < i + 1)
		k = k + size;
	else
		k = k + i;
	return (k);
}
