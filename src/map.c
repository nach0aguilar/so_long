/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:28:06 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/16 19:33:43 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Fuction to duplicate the map

char	**duplicate_map(t_game *game, char *map)
{
	int		row;
	char	**map_dup;

	row = 0;
	map_dup = ft_calloc(get_rows(map) + 1, sizeof(char *));
	while (game->map[row])
	{
		map_dup[row] = ft_strdup(game->map[row]);
		row++;
	}
	map_dup[row] = NULL;
	return (map_dup);
}

// Function to count the number of objects in the map

int	get_rows(char *map)
{
	int		fd;
	int		rows;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (rows);
}

// Function to count and check objects in the map

void	count_and_check(t_game *game)
{
	count_cols_and_rows(game, game->map);
	check_objects(game);
}

// Function to count the number of objects in the map

void	count_objects(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			game->player_n++;
		else if (line[i] == 'E')
			game->moon_n++;
		else if (line[i] == 'C')
			game->btc_n++;
		i++;
	}
}

// Function to pull the map from the file

t_game	*pull_map(char *map)
{
	t_game	*game;
	int		fd;
	int		row;
	char	*line;

	game = ft_calloc(1, sizeof(t_game));
	create_struct(game);
	game->map = ft_calloc(get_rows(map) + 1, sizeof(char *));
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (free(game), NULL);
	row = 0;
	line = get_next_line(fd);
	while (line)
	{
		count_objects(game, line);
		game->map[row] = line;
		row++;
		line = get_next_line(fd);
	}
	game->map_dup = duplicate_map(game, map);
	free(line);
	count_and_check(game);
	close(fd);
	return (game);
}
