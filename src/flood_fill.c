/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:29:04 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/15 15:21:26 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Function to fill the map. Count btc_account and moon_account

void    flood_fill(t_game *game, int row, int col)
{   
    if (row < 0 || row >= game->rows || col < 0 || col >= game->cols
        || game->map_dup[row][col] == '1' || game->map_dup[row][col] == 'X')
        return ;
    if (game->map_dup[row][col] == 'C')
        game->btc_account++;
    if (game->map_dup[row][col] == 'E')
        game->moon_account++;
    game->map_dup[row][col] = 'X';
    flood_fill(game, row + 1, col);
    flood_fill(game, row - 1, col);
    flood_fill(game, row, col + 1);
    flood_fill(game, row, col - 1);
}
