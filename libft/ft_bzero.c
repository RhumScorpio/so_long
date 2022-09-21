/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:33:15 by clesaffr          #+#    #+#             */
/*   Updated: 2021/11/17 20:33:18 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_bzero(void *src, int n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)src;
	while (n--)
	{
		*ptr++ = (unsigned char)0;
	}
	return (src);
}
