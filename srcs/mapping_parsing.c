/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:12:43 by clesaffr          #+#    #+#             */
/*   Updated: 2022/12/22 21:32:38 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

char	**malloc_mapping(int y)
{
	char	**mapping;

	mapping = NULL;
	printf("y == %d\n", y);
	mapping = (char **)malloc(sizeof(char *) * (y + 1));
	if (mapping == NULL)
		return (NULL);
	return (mapping);
}

void	free_mapping_variable(char **mapping)
{
	int	i;

	i = 0;
	while (mapping[i])
		free(mapping[i++]);
	free(mapping);
}

int	inspecting_map(int	init, char *file_name, int x, int y)
{
	int		fd;
	int		gnl;
	int		i;
	char	**mapping;

	if (!init)
		return (0);
	i = 0;
	fd = open(file_name, O_RDONLY);
	mapping = malloc_mapping(y);
	if (!mapping)
		return (0);
	while ((gnl = get_next_line(fd, &mapping[i])) && i < x )
	{
		printf("%s\n", mapping[i]);
		i++;
	}
	free(mapping[i]);
	mapping[i] = '\0';
	// Check if there is a file path	
	free_mapping_variable(mapping);
	close(fd);
	return (1);
}

int	main(int ac, char **av)
{
	int	parsing_res;
	int	x;
	int	y;

	parsing_res = 0;
	if (ac != 2)
	{
		ft_putstr("Put one file please\n");
		return (0);
	}
	parsing_res = parsing(av[1], &x, &y);
	if (parsing_res)
		printf("PARSING IS GOOD\n");
	inspecting_map(parsing_res, av[1], x, y);
	return (0);
}
