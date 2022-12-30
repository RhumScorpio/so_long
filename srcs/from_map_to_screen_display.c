/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_map_to_screen_display.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:18:01 by clesaffr          #+#    #+#             */
/*   Updated: 2022/12/30 00:56:22 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

int	open_xpm_sprites(t_data	*data)
{
	data->spt_wall = mlx_xpm_file_to_image(data->mlx,
			"./sprites/so_long_wall.xpm", &data->spt_x[0], &data->spt_y[0]);
	data->spt_ground = mlx_xpm_file_to_image(data->mlx,
			"./sprites/so_long_ground.xpm", &data->spt_x[1], &data->spt_y[1]);
	data->spt_collect = mlx_xpm_file_to_image(data->mlx,
			"./sprites/so_long_collect.xpm", &data->spt_x[2], &data->spt_y[2]);
	data->spt_exit = mlx_xpm_file_to_image(data->mlx,
			"./sprites/so_long_exit.xpm", &data->spt_x[3], &data->spt_y[3]);
	data->spt_mario = mlx_xpm_file_to_image(data->mlx,
			"./sprites/so_long_mario.xpm", &data->spt_x[4], &data->spt_y[4]);
	if (!data->spt_wall || !data->spt_ground || !data->spt_collect
		|| !data->spt_exit || !data->spt_mario)
	{
		ft_putstr("Sprite opening failed, check sprite directory\n");
		return (0);
	}
	else
		return (1);
}

void	put_image_from_char(t_data *data, int x, int y)
{
	char	c;

	c = data->map[y][x];
	if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->mlxWin,
			data->spt_mario, x * 64, y * 64);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->mlxWin,
			data->spt_collect, x * 64, y * 64);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->mlxWin,
			data->spt_exit, x * 64, y * 64);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx, data->mlxWin,
			data->spt_ground, x * 64, y * 64);
	else if (c == '1')
		mlx_put_image_to_window(data->mlx, data->mlxWin,
			data->spt_wall, x * 64, y * 64);
}

void	displaying_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->y)
	{
		while (x < data->x)
		{
			put_image_from_char(data, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

int	destroy_sprites(t_data *data)
{
	if (data->spt_wall)
		mlx_destroy_image(data->mlx, data->spt_wall);
	if (data->spt_ground)
		mlx_destroy_image(data->mlx, data->spt_ground);
	if (data->spt_collect)
		mlx_destroy_image(data->mlx, data->spt_collect);
	if (data->spt_exit)
		mlx_destroy_image(data->mlx, data->spt_exit);
	if (data->spt_mario)
		mlx_destroy_image(data->mlx, data->spt_mario);
	return (0);
}
