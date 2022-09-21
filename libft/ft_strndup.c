/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:47:53 by clesaffr          #+#    #+#             */
/*   Updated: 2022/08/28 12:48:48 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!src)
		return (NULL);
	tmp = malloc(sizeof(char) * (n + 1));
	if (!tmp)
		return (0);
	while (*(src + i) != '\0' && i < n)
	{
		tmp[i] = src[i];
		++i;
	}
	tmp[i] = '\0';
	return (tmp);
}
