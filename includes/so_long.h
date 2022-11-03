/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:09:01 by clesaffr          #+#    #+#             */
/*   Updated: 2022/10/28 20:36:03 by clesaffr         ###   ########.fr       */
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

typedef struct s_scrn
{
	void	*img;
	int		width;
	int		height;
}				t_scrn;

typedef struct s_data
{
	void	*mlx;
	void	*mlxWin;
	void	*mlxImg;
	t_scrn	*sprite;
	char	*addrImg;
	int		*bpp;
	int		*size;
	int		*endian;
}				t_data;

#endif
