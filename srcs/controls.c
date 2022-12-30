/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:11:45 by clesaffr          #+#    #+#             */
/*   Updated: 2022/12/30 00:48:01 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

int	change_map(t_data *data, int movy, int movx)
{
	char	c;

	c = data->map[data->mario_y + movy][data->mario_x + movx];
	data->map[data->mario_y + movy][data->mario_x + movx] = 'P';
	data->mario_y += movy;
	data->mario_x += movx;
	displaying_map(data);
	if (c == 'C')
		data->collect++;
	if (c == 'E' && data->collect == data->total)
		return (++data->game_finished);
	return (0);
}

int	move_persona(t_data *data, int d)
{
	ft_putnbr_fd(++data->move, 1);
	ft_putstr(" total steps\n");
	if (data->mario_y == data->exit_y && data->mario_x == data->exit_x)
		data->map[data->mario_y][data->mario_x] = 'E';
	else
		data->map[data->mario_y][data->mario_x] = '0';
	if (d == 1)
		return (change_map(data, -1, 0));
	else if (d == 2)
		return (change_map(data, 0, -1));
	else if (d == 3)
		return (change_map(data, 1, 0));
	else if (d == 4)
		return (change_map(data, 0, 1));
	return (0);
}

int	direction(int key, t_data *data)
{
	int	end;

	end = 0;
	if (key == UP && data->map[data->mario_y - 1][data->mario_x] != '1')
		end = move_persona(data, 1);
	else if (key == LEFT && data->map[data->mario_y][data->mario_x - 1] != '1')
		end = move_persona(data, 2);
	else if (key == DOWN && data->map[data->mario_y + 1][data->mario_x] != '1')
		end = move_persona(data, 3);
	else if (key == RIGHT && data->map[data->mario_y][data->mario_x + 1] != '1')
		end = move_persona(data, 4);
	if (key == ESC || end == 1)
		close_window(data);
	return (0);
}
