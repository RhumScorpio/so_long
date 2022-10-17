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
#include <stdint.h>
#include <stdio.h>

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->mlxImg);
	mlx_destroy_window(data->mlx, data->mlxWin);
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
//
// CONSEILS DES PROS
// Lire Clean Code regulierement
// Les fonctions cascades qui return des fonctions
// La super fonction a variable STATIC
// La norme a 10 lignes par FUNCTION en theorie si c'est au dessus on peut encore la reduire
// pouvoir garder les fonctions en memoire si elle sont bien c'est facile
// Le tri des fonctions en ordre d'execution du bas vers le haut
// La fonction qui fait plusieurs chose doit etre bien utilisee
// Jamais plusieurs niveaux de if dans les while > 1 seul niveau autorise
// TESTER PUTAIIIIIIIIN le tester doit etre ADAPTE pour tout tester en une seule fois
// Prendre la ritaline ou concerta apres avoir mange et pas trop au debut
// Il faudrait pouvoir lire le code TRES FACILEMENT apres tout ca
// L'important c'est aussi de savoir ce qu'on veut ecrire comme style de code
// L'OPTIMISATION PEUT ALLER TOUJOURS PLUS LOIN

int	frame(t_data *data)
{
    void	*sprite_img;
    int x;
    int	y;

    x = data->sprite->height;
    y = data->sprite->height;
    printf("x/%d, y/%d", x, y);
    sprite_img = data->sprite->img;
    //data->mlxImg = mlx_new_image(data->mlxWin, 64, 64);
    //data->addrImg = mlx_get_data_addr(data->mlxWin, data->bpp, data->size, data->endian);
    mlx_put_image_to_window(data->mlx, data->mlxWin, sprite_img, 0, 0);
    /*while (x < 120 && y < 120)
    {
        //mlx_pixel_put(data->mlx, data->mlxWin, x, y, 1);
        x++;intra
        y++;
    }*/
    //mlx_put_image_to_window(data->mlx, data->mlxWin, data->mlxImg, 0, 0);
    return (1);
}

void	get_xpm_files()
{

}

int	main(void)
{
	int		width;
	int		height;
	t_data	data;
	t_scrn	sprite;

	width = 1920;
	height = 1080;
	data.mlx = mlx_init();
	if (!data.mlx)
		return (0);
	data.mlxWin = mlx_new_window(data.mlx, width, height, "Hello world!");
	//get the XPM into a *char arrangement, pass the *char arrangement into double array
	data.mlxImg = mlx_new_image(data.mlx, width, height);
	sprite.img = mlx_xpm_file_to_image(data.mlx, "mario_1_.xpm", &(sprite.width), &(sprite.height));
	if (!sprite.img)
		return (0);
	data.sprite = &sprite;
	mlx_key_hook(data.mlxWin, direction, &data);
	mlx_hook(data.mlxWin, 17, 1L<<0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
