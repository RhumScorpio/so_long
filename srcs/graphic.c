/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 07:58:12 by clesaffr          #+#    #+#             */
/*   Updated: 2022/12/27 14:32:24 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdint.h>
#include <stdio.h>

int	close_window(t_data *data)
{
	free_mapping_variable(data->map);
	mlx_destroy_image(data->mlx, data->mlxImg);
	mlx_destroy_window(data->mlx, data->mlxWin);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	direction(int key, t_data *data)
{
	printf("%d\n", key);
	if (key == 65307)
		close_window(data);
	return (0);
}
//direction must be changing data to the right direction. IN LOOP FUNCT frame creation.
// MALLOC FOR --> sprites
// MALLOC FOR --> global error YOU CAN MAKE A FUNCTION WITH STATIC DECLARATION AND CALL IT TO RETURN A VALUE AROUND THE CODE
//
//image creation must be from the imgAddr get from XPMimg *Mur *Sol *Perso *Sol+Collectible *Sol+Sortie  
//frame must be secondary to the creation of image
//IMPORTANT ---> char modification must be in stack, cp img addr from sprite into buffers that can be used to copy char into the RIGHT CONFIGURATION
/*
int	frame(t_data *data)
{
    void    *sprite_img;
    int               x;
    int	              y;

    x = data->sprite->height;
    y = data->sprite->height;
    printf("x/%d, y/%d", x, y);
    sprite_img = data->sprite->img;
    //data->mlxImg = mlx_new_image(data->mlxWin, 64, 64);
    //data->addrImg = mlx_get_data_addr(data->mlxWin, data->bpp, data->size, data->endian);
    mlx_put_image_to_window(data->mlx, data->mlxWin, sprite_img, 0, 0);
    while (x < 120 && y < 120)
    {
        //mlx_pixel_put(data->mlx, data->mlxWin, x, y, 1);
        x++;intra
        y++;
    }
    //mlx_put_image_to_window(data->mlx, data->mlxWin, data->mlxImg, 0, 0);
    return (1);
}*/

int	get_xpm_files(void	*mlx, t_scrn *spt, char *file)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	printf("file = %s \n", file);
	spt->img = mlx_xpm_file_to_image(mlx, file, &x, &y);
	spt->width = x;
	spt->height = y;
	printf("x = %d, y = %d\n", x, y);
	if (!spt->img)
		return (0);
	else
		return (1);
}

int	opening_graphic_ressources_xpm(t_data *data)
{
	int	i;

	i = 0;
	printf("OPEN");
	i += get_xpm_files(data->mlx, data->spt_wall, "./sprites/so_long_wall.xpm");
	i += get_xpm_files(data->mlx, data->spt_ground, "./sprites/so_long_ground.xpm");
	i += get_xpm_files(data->mlx, data->spt_collect, "./sprites/so_long_collect.xpm");
	i += get_xpm_files(data->mlx, data->spt_exit, "./sprites/so_long_exit.xpm");
	i += get_xpm_files(data->mlx, data->spt_mario, "./sprites/so_long_mario.xpm");
	if (i == 5)
		return (1);
	else
		return (0);

}
	//sprite.img = mlx_xpm_file_to_image(data.mlx, "mario_1_.xpm", &(sprite.width), &(sprite.height));
int	main_parsing(int ac, char **av, int *x, int *y)
{
	int	parsing_res;
	
	parsing_res = 0;
	if (ac != 2)
	{
		ft_putstr("Put one file please\n");
		return (0);
	}
	parsing_res = parsing(av[1], x, y);
	if (inspecting_map(parsing_res, av[1], *x, *y))
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	int		width;
	int		height;
	static t_data	data;
	static t_scrn	spt;
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (main_parsing(ac, av, &x, &y))
	{
		printf("INITIALIZED\n");
		data.mlx = mlx_init();
		if (!data.mlx)
			return (0);
	}
	// OPEN ALL RESSOURCES
	printf("x = %d | y = %d\n", x, y);
//	if (!opening_graphic_ressources_xpm(&data))
//		return (0);
	printf("x = %d | y = %d\n", x, y);
	data.map = allocating_full_map(av[1], x, y);
	width = 64 * x;
	height = 64 * y;
	data.mlxWin = mlx_new_window(data.mlx, width, height, "Hello world!");
	data.mlxImg = mlx_new_image(data.mlx, width, height);
	spt.img = mlx_xpm_file_to_image(data.mlx, "./sprites/so_long_wall.xpm", &(spt.width), &(spt.height));
    mlx_put_image_to_window(data.mlx, data.mlxWin, spt.img, 0, 0);
	mlx_destroy_image(data.mlx, spt.img);
	//get the XPM into a *char arrangement, pass the *char arrangement into double array
    //mlx_put_image_to_window(data->mlx, data->mlxWin, data->mlxImg, 0, 0);
	mlx_key_hook(data.mlxWin, direction, &data);
	mlx_hook(data.mlxWin, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
