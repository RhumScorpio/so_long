/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 07:58:12 by clesaffr          #+#    #+#             */
/*   Updated: 2022/08/12 04:54:23 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	frame(void *mlx_win)
{
	int		*bits_per_pixel;
	int		*size_line;
	int		*endian;
	char 	*str;
	void	*mlx_image;
	int		i;

	i = 0;
	str = NULL;
	while (i++ < 10)
	{
		mlx_image = mlx_new_image(mlx_win, 1980, 1080);
		str = mlx_get_data_addr(mlx_image, bits_per_pixel, size_line, endian);
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_win);
	return (0);
}
