/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:09:01 by clesaffr          #+#    #+#             */
/*   Updated: 2022/12/26 00:50:03 by clesaffr         ###   ########.fr       */
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

typedef struct s_screens
{
    t_scrn sprite_wall;
    t_scrn sprite_sol;
    t_scrn sprite_mario;
    t_scrn sprite_collect;
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



void	print_items(t_items *items);
int		if_items_valid(t_items *items);
int		items_are_valid(t_items *items);

int		the_line_is_wall(char *line);
int		is_some_item(char c, t_items *items);
int		the_line_is_in(char *line, t_items *items);
int		checkif_line_valid(int i, char **line, t_items *items);


int		pre_gnl_to_y(char *file_name);
int		gnl_file(char *line, int fd, int y, t_items *items);

int 	try_opening(char *file_name);
int		check_file_extension(char *file_name);
int		check_file_lines(char *file_name, int *x, int *y);
int		parsing(char *file_name, int *x, int *y);

int 	check_path_to_win_game(char **mapping, int collectibles);

int		inspecting_map(int	init, char *file_name, int x, int y);
void	free_mapping_variable(char **mapping);
void	close_mapping_variable(char **mapping);
void	print_mapping(char **mapping);
char	**malloc_mapping(int y);


#endif
