/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 23:02:58 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/11 23:22:18 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Function to count the rows of the map

int count_rows(char *map)
{
    int i;
    int rows;

    i = 0;
    rows = 0;
    while(map[i])
    {
        if (map[i] == '\n')
            rows++;
        i++;
    }
    return (rows);
}

// Function to count the columns of the map

int count_cols(char *map)
{
    int i;
    int cols;

    i = 0;
    cols = 0;
    while(map[i] && map[i] != '\n')
    {
        cols++;
        i++;
    }
    return (cols);
}

void count_cols_and_rows(t_game *game,char *map)
{
    game->rows = count_rows(map);
    game->cols = count_cols(map);
}