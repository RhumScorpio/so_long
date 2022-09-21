/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:55:45 by clesaffr          #+#    #+#             */
/*   Updated: 2020/02/22 10:28:49 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *p, int i, int chr)
{
	char	c;
	int		n;

	n = 0;
	c = chr;
	while (n < i)
	{
		if (*p == c)
			return ((char *)p);
		++p;
	}
	return (0);
}
