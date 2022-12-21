/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:47:25 by clesaffr          #+#    #+#             */
/*   Updated: 2022/12/20 20:42:15 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

int the_line_is_wall(char *line)
{
    int i;

    i = 0;
	printf("checked wall\n");
    while (line[i] == '1')
        ++i;
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

	printf("checked in\n");
    if (line[0] != '1')
        return (-1);
    i = 1;
    while (line[i] && is_some_item(line[i], items) != -1)
        ++i;
    if (line[i - 1] != '1')
        return (-1);
    return (i);
}

int checkif_line_valid(int i, char **line, t_items *items)
{
    if (i == 1 || i == 0)
        return (the_line_is_wall(*line));
    else
        return (the_line_is_in(*line, items));
}

void print_items(t_items *items)
{
    printf("collectibles = %d\npersona = %d\nexit = %d\n", items->collect, items->persona, items->exit);
}

int items_are_valid(t_items *items)
{
    if (items->collect == 0 || items->persona != 1 || items->exit != 1)
        return (0);
    else
        return (1);
}

int try_opening(char *file_name)
{
	int	fd;

    fd = open(file_name, O_RDONLY);
    if (fd == -1)
    {
        ft_putstr("Opening failed, does file exist?");
        return (0);
    }
	close(fd);
	//if everything goes well return 1
	return (1);
}

int	check_file_extension(char *file_name)
{
	int	i;

	i = ft_strlen(file_name);
    if (i < 5)
    {
        ft_putstr("File name is too short");
        return (0);
    }
    else if (file_name[i - 4] == '.' && file_name[i - 3] == 'b' 
        && file_name[i - 2] == 'e' && file_name[i - 1] == 'r')
		return(try_opening(file_name));
    else
    {
        ft_putstr("File does not end with .ber");
        return (0);
    }
}

int	if_items_valid(t_items items)
{
    if (items_are_valid(&items))
    {
        ft_putstr("File is a good file!\n");
        print_items(&items);
        return (1);
    }
    else
    {
        ft_putstr("Items not valid\n");
        print_items(&items);
        return (-1);
    }
}

int	gnl_file(char *line, int fd, int *x, t_items *items)
{
	int	gnl;
	int	y;
	int	i;

	gnl = get_next_line(fd, &line);
	*x = gnl;
	y = 0;
	i = 1;
    while (gnl)
    {
        printf("line = %s\n", line);
        if (checkif_line_valid(i, &line, items) != *x)
            break;
        else
            printf("Line is valid\n");
        i++;
        free(line);
        line = NULL;
		gnl = get_next_line(fd, &line);
		if (gnl == 0)
			i = 0;
        y++;
    }
    if (*x < 3)
        return (0);
	else
		return (y);
}

int	check_file_lines(char *file_name)
{
	//Where should I store map info?
	//When do I create the data struct?
	//I should do a first gnl for error handling THEN do a malloc with the data
    int     fd;
    int     y;
    int     x;
    static t_items items;
    char    *line;
  
    fd = open(file_name, O_RDONLY);
	x = 0;
    line = NULL;
	y = gnl_file(line, fd, &x, &items);
    printf("Width is x --> %d\nLenght is y --> %d\n", x, y);
    free(line);
    close(fd);
	return(if_items_valid(items));
}

int	parsing(char *file_name)
{
    //Check File Extension
    if (!file_name)
        return (0);
    check_file_extension(file_name);
	// Get Next Line
	check_file_lines(file_name);
	return (1);
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        ft_putstr("Put one file please\n");
        return (0);
    }
    parsing(av[1]);
    return (0);
}
