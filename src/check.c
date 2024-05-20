/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:12:45 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/20 13:24:40 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Function to check the extension of the map

void	check_extension(char *map)
{
	char	*extension;

	extension = ft_strrchr(map, '.');
	if (!extension || ft_strncmp(extension, ".ber", 4) != 0)
	{
		ft_putstr_fd("Error: Invalid extension\n", 2);
		exit(EXIT_FAILURE);
	}
}

// Function to check the number of objects

void	check_objects(t_game *game)
{
	if (game->player_n != 1)
		error_free("Error: The map must have one player\n", game);
	if (game->moon_n != 1)
		error_free("Error: The map must have one moon\n", game);
	if (game->btc_n < 1)
		error_free("Error: The map must have at least one bitcoin\n", game);
}

// Function to check the walls

void	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (i == 0 || i == game->rows - 1 || j == 0 || j == game->cols - 1)
			{
				if (game->map[i][j] != '1' && game->map[i][j] != '\n')
					error_free("Error: The map must be surrounded by walls\n",
						game);
			}
			j++;
		}
		i++;
	}
}

// Function to check the map is a rectangle

void	check_rectangle(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != game->cols)
			error_free("Error: The map must be a rectangle\n", game);
		i++;
	}
}

// Function to check invalid characters

void	check_invalid_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'P' && game->map[i][j] != 'C'
				&& game->map[i][j] != 'E' && game->map[i][j] != '\n')
				error_free("Error: The map cannot contain invalid characters",
					game);
			j++;
		}
		i++;
	}
}
