/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnlstrjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 22:26:15 by clesaffr          #+#    #+#             */
/*   Updated: 2022/09/04 21:04:57 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnlstrjoin(char *s1, char *s2)
{
	char	*ret;

	if (!s1 && !s2)
		return (NULL);
	else if (s1 && !s2)
		ret = ft_strdup(s1);
	else if (!s1 && s2)
		ret = ft_strdup(s2);
	else
	{
		ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!ret)
			return (NULL);
		ret = ft_strcpy(ret, s1);
		ret = ft_strcat(ret, s2);
	}
	return (ret);
}
