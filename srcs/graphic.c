/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 07:58:12 by clesaffr          #+#    #+#             */
/*   Updated: 2022/12/30 00:59:53 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdint.h>
#include <stdio.h>

void	put_end_sentence(int final_moves)
{
	ft_putstr("Game finished in ");
	ft_putnbr_fd(final_moves, 1);
	ft_putstr(" steps. Congratulations!\n");
}

int	close_window(t_data *data)
{
	if (data->game_finished)
		put_end_sentence(data->move);
	free_mapping_variable(data->map);
	destroy_sprites(data);
	mlx_destroy_window(data->mlx, data->mlxWin);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	main_parsing(int ac, char **av, t_data *data)
{
	if (ac != 2)
	{
		ft_putstr("Put one file please\n");
		return (0);
	}
	data->total = parsing(av[1], &data->x, &data->y);
	if (inspecting_map(data->total, av[1], data->x, data->y))
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	static t_data	data;

	if (main_parsing(ac, av, &data))
		data.mlx = mlx_init();
	else
		return (0);
	data.map = allocating_full_map(av[1], data.x, data.y);
	if (!data.mlx || !data.map)
		return (0);
	setting_char_position('P', data.map, &data.mario_x, &data.mario_y);
	setting_char_position('E', data.map, &data.exit_x, &data.exit_y);
	data.screen_y = 64 * data.y;
	data.screen_x = 64 * data.x;
	data.mlxWin = mlx_new_window(data.mlx, data.screen_x,
			data.screen_y, "clesaffr's so_long");
	if (open_xpm_sprites(&data))
		displaying_map(&data);
	else
		return (close_window(&data));
	mlx_key_hook(data.mlxWin, direction, &data);
	mlx_hook(data.mlxWin, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
