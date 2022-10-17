/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:47:25 by clesaffr          #+#    #+#             */
/*   Updated: 2022/08/27 14:47:29 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	parsing(char *file_name)
{
	//PREMIERE LIGNE ET DERN 111111
    //TOUT COMMENCE PAR UN 1 ET FINI PAR UN 111111
    //char valides uniquement 0 1 C E P
   //meme longueur et pas de doublons sorties et character
    
    // verifier les permissions du fichier

    // 1 -- parsing: 
     // - verif ".ber" >4 / nom du fichier / - format map (map carree, mur en vertical et horizontal) / - ligne vide au milieu / -nb E / C / P

    // 2 -- path finding

    // 3 -- structs

    // 4 -- activer les keys

    // 5 --travail graphique avec la mlx
    
    char    *f_extension;
    int     i;

    f_extension = "ber";
    i = 0;
    if (ft_strlen(file_name) < 4)
        return (0);
    while (file_name[i] != '.')
        i++;
    if ((file_name + i) != f_extension)
        return (0);
    return(1);

    printf("\n");
}
