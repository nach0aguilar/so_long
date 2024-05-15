/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:42:26 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/15 13:43:33 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Function to get the player position

void    get_player_position(t_game *game)
{
    int row;
    int col;

    row = 0;
    while (row < game->rows)
    {
        col = 0;
        while (col < game->cols)
        {
            if (game->map[row][col] == 'P')
            {
                game->x_pos = col;
                game->y_pos = row;
                return ;
            }
            col++;
        }
        row++;
    }
}