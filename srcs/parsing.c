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

int the_line_is_wall(char *line)
{
    int i;

    i = 0;
    while (line[i] == '1')
        i++;
    return (i);
}

//struct error de C P E qui indique si y a bien un de chaques. collect persona et exit

int is_some_item(char c, t_items *items)
{
    if (c == 'C')
        return (items->collect++);
    else if (c == 'P')
        return (items->persona++);
    else if (c == 'E')
        return (items->exit++);
    else if (c == '1' || c == '0')
        return (1);
    else
        return (-1);
}

int the_line_is_in(char *line, t_items *items)
{
    int i;

    if (line[0] != '1')
        return (-1);
    i = 1;
    while (is_some_item(line[i], items) != -1)
        i++;
    return (i);
}

int checkif_line_valid(int i, char **line, t_items *items)
{
    if (i == 1 || i == 0)
        return (the_line_is_wall(*line));
    else
        return (the_line_is_in(*line, items));
}

int	parsing(char *file_name)
{
    char    *line;
    int     fd;
    int     i;

    fd = 0;
    //Check File Extension
    i = ft_strlen(file_name);
    if (i < 5)
    {
        ft_putstr("File name is too short");
        return (0);
    }
    if (file_name[i - 4] == '.' && file_name[i - 3] == 'b' 
        && file_name[i - 2] == 'e' && file_name[i - 1] == 'r')
    {
        fd = open(file_name, O_RDONLY);
        if (i == -1)
            ft_putstr("Opening failed");
    }
    else
        ft_putstr("File does not end with .ber");
    // Get Next Line

    int     y;
    int     x;
    int     ret;
    t_items items;

    ret = get_next_line(fd, &line);
    if (ret < 3)
        return (0);
    x = ret;
    i = 1;
    while (ret == x)
    {
        if (checkif_line_valid(i, &line, &items) != x)
            return (0);
        ret = get_next_line(fd, &line);
        i++;
    }
    y = i;
    i = 0;
    if (checkif_line_valid(i, &line, &items) < 0)
        return (0);
    else
        return (1);
}
