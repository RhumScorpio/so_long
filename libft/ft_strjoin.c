/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 14:31:25 by clesaffr          #+#    #+#             */
/*   Updated: 2021/11/17 20:24:45 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int				i;
	int				j;
	char			*p;
	unsigned int	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = (char *)malloc(size * sizeof(*p));
	if (!p)
		return (NULL);
	i = -1;
	while (i++ < ft_strlen(s1))
		p[i] = s1[i];
	j = i - 1;
	i = -1;
	while (i++ < ft_strlen(s2))
		p[j + i] = s2[i];
	p[j + i + 1] = '\0';
	return (p);
}
