/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 22:36:48 by clesaffr          #+#    #+#             */
/*   Updated: 2021/11/17 20:22:22 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	nbtest;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nbtest = -1 * nb;
	}
	else
		nbtest = nb;
	if (nbtest >= 10)
	{
		ft_putnbr_fd(nbtest / 10, fd);
	}
	ft_putchar_fd((nbtest % 10 + '0'), fd);
}
