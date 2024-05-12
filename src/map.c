/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:28:06 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/12 21:15:08 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Function to count the number of objects in the map

int     get_rows(char *map)
{
    int fd;
    int rows;
    char *line;

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

// Function to count the number of objects in the map

void    count_objects(t_game *game, char *line)
{
    int i;

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

t_game *pull_map(char *map)
{
    t_game *game;
    int fd;
    int row;
    char *line;

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
    free(line);
    count_cols_and_rows(game, game->map);
    check_objects(game);
    close(fd);
    return (game);
}
