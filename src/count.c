/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 23:02:58 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/12 21:28:26 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Function to count the rows of the map

int count_rows(char **map)
{
    int i;
    int j;
    int rows;

    i = 0;
    rows = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
            j++;
        rows++;
        i++;
    }
    return (rows);
}

// Function to count the columns of the map

int count_cols(char **map)
{
    int i;
    int j;
    int cols;

    i = 0;
    j = 0;
    cols = 0;
    while(map[i][j] != '\n')
    {
        cols++;
        j++;
    }
    return (cols);
}

void count_cols_and_rows(t_game *game, char **map)
{
    game->rows = count_rows(map);
    game->cols = count_cols(map);
}