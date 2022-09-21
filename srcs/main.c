/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 07:58:12 by clesaffr          #+#    #+#             */
/*   Updated: 2022/09/20 21:22:36 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	frame(t_data *data)
{
	/*int x;
	int	y;

	x = 0;
	y = 0;*/
	t_screen	sprite;

	//data->mlxImg = mlx_new_image(data->mlxWin, 1920, 1080);
	sprite.img = mlx_xpm_file_to_image(data->mlx, "mario_1_.xpm", &(sprite.width), &(sprite.height));
	//(void)img;
	mlx_put_image_to_window(data->mlx, data->mlxWin, sprite.img, 0, 0);

	//data->addrImg = mlx_get_data_addr(data->mlxWin, data->bpp, data->size, data->endian);
	/*while (x < 120 && y < 120)
	{
		//mlx_pixel_put(data->mlx, data->mlxWin, x, y, 1);
		x++;
		y++;
	}*/
	//mlx_put_image_to_window(data->mlx, data->mlxWin, data->mlxImg, 0, 0);
	return (1);
}

int	direction(int key, t_data *data)
{
	printf("%d\n", key);
	if (key == 65307)
	{
	//	mlx_destroy_image(data->mlxWin, data->mlxImg);
		mlx_destroy_window(data->mlx, data->mlxWin);
	//	mlx_destroy_display(data->mlx);
	}
	return (0);
}

int	direction2(int key)
{
	printf("%d\n", key);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.mlxWin = mlx_new_window(data.mlx, 1920, 1080, "Hello world!");
	mlx_key_hook(data.mlxWin, direction, &data);
	mlx_mouse_hook(data.mlxWin, direction2, NULL);
	frame(&data);
	mlx_loop(data.mlx);
	return (0);
}
