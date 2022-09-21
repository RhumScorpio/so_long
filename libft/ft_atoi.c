/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 02:10:12 by clesaffr          #+#    #+#             */
/*   Updated: 2022/06/18 21:26:50 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	parsing_for_sign(const char *str, int *index)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] && (str[i] == ' ' || (str[i] >= 7 && str[i] <= 13)))
		i++;
	while (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	*index = i;
	return (sign);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	i;

	result = 0;
	i = 0;
	sign = parsing_for_sign(str, &i);
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
