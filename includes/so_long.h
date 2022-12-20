/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:09:01 by clesaffr          #+#    #+#             */
/*   Updated: 2022/11/03 21:07:05 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../minilibx-linux/mlx_int.h"
#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"

typedef struct	s_items
{
	int	collect;
	int	persona;
	int	exit;
}				t_items;

typedef struct s_scrn
{
	void	*img;
	int		width;
	int		height;
}				t_scrn;

typedef struct s_map
{
   int  width;
   int  height;
   int  width_img;
   int  height_img;
}              t_map;

typedef struct s_screens;
{
    s_scrn sprite_wall;
    s_scrn sprite_sol;
    s_scrn sprite_mario;
    s_scrn sprite_collect;
}               t_screens;

typedef struct s_data
{
	void	*mlx;
	void	*mlxWin;
	void	*mlxImg;
	t_screens	*sprites;
    t_map   *map;
	char	*addrImg;
	int		*bpp;
	int		*size;
	int		*endian;
}				t_data;

#endif
