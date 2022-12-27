/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:12:43 by clesaffr          #+#    #+#             */
/*   Updated: 2022/12/27 15:31:30 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

char	**malloc_mapping(int y)
{
	char	**mapping;

	mapping = NULL;
	mapping = (char **)malloc(sizeof(char *) * (y + 1));
	if (mapping == NULL)
		return (NULL);
	mapping[y] = 0;
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

void	close_mapping_variable(char	**mapping)
{
	free(*mapping);
	*mapping = '\0';
}
char	**allocating_full_map(char *file_name, int x, int y)
{
	int		gnl;
	int		i;
	char	**mapping;
	int		fd;
	
	i = 0;
	fd = open(file_name, O_RDONLY);
	mapping = malloc_mapping(y);
	if (!mapping)
		return (NULL);
	while ((gnl = get_next_line(fd, &mapping[i])) && i < x )
		i++;
	close_mapping_variable(&mapping[i]);
	close(fd);
	return (mapping);
}

int	inspecting_map(int	init, char *file_name, int x, int y)
{
	int		error;
	char	**mapping;

	if (!init)
		return (0);
	mapping = allocating_full_map(file_name, x, y);
	error = check_path_to_win_game(mapping, init);
	free_mapping_variable(mapping);
	return (error);
}
