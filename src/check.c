/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:12:45 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/11 23:28:26 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Function to check the extension of the map

void check_extension(char *map)
{
    char *extension;

    extension = ft_strrchr(map, '.');
    if (!extension || ft_strncmp(extension, ".ber", 4) != 0)
        error_argument("Error: Invalid extension\n");
}

// Function to check the number of objects

void check_objects(t_game *game)
{
    if (game->player_n != 1)
        error_argument("Error: The map must have one player\n");
    if (game->moon_n != 1)
        error_argument("Error: The map must have one moon\n");
    if (game->btc_n < 1)
        error_argument("Error: The map must have at least one bitcoin\n");
}

// Function to check the walls

void check_walls(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (i == 0 || i == game->rows - 1 || j == 0 || j == game->cols - 1)
            {
                if (game->map[i][j] != '1')
                    error_argument("Error: The map must be surrounded by walls\n");
            }
            j++;
        }
        i++;
    }
}