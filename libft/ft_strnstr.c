/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:38:26 by clesaffr          #+#    #+#             */
/*   Updated: 2021/11/17 20:25:15 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*to_find == '\0')
		return (str);
	while (*(str + i) != '\0' && i < len)
	{
		j = 0;
		while (*(to_find + j) == *(str + i + j) && i + j < len)
		{
			if (*(to_find + j + 1) == '\0')
				return (str + i);
			j++;
		}
		i++;
	}
	return (0);
}
