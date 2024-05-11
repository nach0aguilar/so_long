/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:27:35 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/11 20:12:58 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Creating the structure for the game

void create_struct(t_game *game)
{
    // game->mlx = NULL;
    game->map = NULL;
    game->player = 'P';
    game->moon = 'E';
    game->btc = 'C';
    game->player_n = 0;
    game->moon_n = 0;
    game->btc_n = 0;
    // game->player_img = NULL;
    // game->btc_img = NULL;
    // game->moon_img = NULL;
    // game->floor_img = NULL;
    // game->wall_img = NULL;
}