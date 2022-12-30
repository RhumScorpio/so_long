/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:09:01 by clesaffr          #+#    #+#             */
/*   Updated: 2022/12/30 15:23:14 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define ESC 65307
# define UP 119
# define LEFT 97
# define DOWN 115
# define RIGHT 100

typedef struct s_items
{
	int	collect;
	int	persona;
	int	exit;
}				t_items;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;

	int		spt_x[5];
	int		spt_y[5];

	void	*spt_wall;
	void	*spt_ground;
	void	*spt_collect;
	void	*spt_exit;
	void	*spt_mario;

	char	**map;
	int		total;
	int		collect;
	int		move;
	int		game_finished;

	int		y;
	int		x;
	int		mario_y;
	int		mario_x;
	int		exit_y;
	int		exit_x;
	int		screen_y;
	int		screen_x;
}				t_data;

// core_parsing.c
int		try_opening(char *file_name);
int		check_file_extension(char *file_name);
int		check_file_lines(char *file_name, int *x, int *y);
int		parsing(char *file_name, int *x, int *y);

// line_reading.c
int		pre_gnl_to_y(char *file_name);
int		gnl_file(char *line, int fd, int y, t_items *items);

// checking_line.c
int		the_line_is_wall(char *line);
int		is_some_item(char c, t_items *items);
int		the_line_is_in(char *line, t_items *items);
int		checkif_line_valid(int i, char **line, t_items *items);

// checking_items.c
int		if_items_valid(t_items *items);
int		items_are_valid(t_items *items);
int		finding_little_e(char **map);
void	setting_char_position(char c, char **map, int *x, int *y);

// mapping_parsing.c
int		inspecting_map(int init, char *file_name, int x, int y);
void	free_mapping_variable(char **mapping);
void	close_mapping_variable(char **mapping);
char	**allocating_full_map(char *file_name, int x, int y);
char	**malloc_mapping(int y);

// copy_map_for_path_search.c
int		mapping_x(char **mapping);
int		mapping_y(char **mapping);
char	**copy_map_for_path_search(char **mapping);

// finding_a_valid_path.c
int		check_path_to_win_game(char	**mapping, int collectibles);

// from_map_to_screen_display.c
int		open_xpm_sprites(t_data	*data);
void	displaying_map(t_data *data);
int		destroy_sprites(t_data *data);

// controls.c
int		direction(int key, t_data *data);

// graphic.c
int		close_window(t_data *data);

#endif
