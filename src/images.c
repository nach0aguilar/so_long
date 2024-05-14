/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:17:57 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/14 14:41:39 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    img_player_to_map(t_game *game, char **map, int col, int row)
{
    if(map[row][col] == 'P')
    {
        mlx_image_to_window(game->mlx, game->floor_img, col * 64, row * 64);
        mlx_image_to_window(game->mlx, game->player_img, col * 64, row * 64);
        if((mlx_image_to_window(game->mlx, game->player_img, col * 64, row * 64)) == -1)
            error_argument("Error: Failed to load player\n");
    }
}

void    img_btc_to_map(t_game *game, char **map, int col, int row)
{
    if(map[row][col] == 'C')
    {
        mlx_image_to_window(game->mlx, game->floor_img, col * 64, row * 64);
        mlx_image_to_window(game->mlx, game->btc_img, col * 64, row * 64);
        if((mlx_image_to_window(game->mlx, game->btc_img, col * 64, row * 64)) == -1)
            error_argument("Error: Failed to load btc\n");
    }
}

void    img_moon_to_map(t_game *game, char **map, int col, int row)
{
    if(map[row][col] == 'E')
    {
        mlx_image_to_window(game->mlx, game->moon_img, col * 64, row * 64);
        if((mlx_image_to_window(game->mlx, game->moon_img, col * 64, row * 64)) == -1)
            error_argument("Error: Failed to load moon\n");
    }
}

void    img_floor_to_map(t_game *game, char **map, int col, int row)
{
    if(map[row][col] == '0')
    {
        mlx_image_to_window(game->mlx, game->floor_img, col * 64, row * 64);
        if((mlx_image_to_window(game->mlx, game->floor_img, col * 64, row * 64)) == -1)
            error_argument("Error: Failed to load floor\n");
    }
}

void    img_wall_to_map(t_game *game, char **map, int col, int row)
{
    if(map[row][col] == '1')
    {
        mlx_image_to_window(game->mlx, game->wall_img, col * 64, row * 64);
        if((mlx_image_to_window(game->mlx, game->wall_img, col * 64, row * 64)) == -1)
            error_argument("Error: Failed to load wall\n");
    }
}