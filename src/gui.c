/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:47:31 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/13 22:18:05 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Function to load the images

void    load_gui(t_game *game)
{
    mlx_texture_t  *texture;
    
    texture = mlx_load_png("textures/floor.png");
    game->floor_img = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);
    texture = mlx_load_png("textures/wall.png");
    game->wall_img = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);
    texture = mlx_load_png("textures/astronaut.png");
    game->player_img = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);
    texture = mlx_load_png("textures/exit.png");
    game->moon_img = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);
    texture = mlx_load_png("textures/bitcoin.png");
    game->btc_img = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);
}

// Function to delete the images

void    delete_gui(t_game *game)
{
    mlx_delete_image(game->mlx, game->floor_img);
    mlx_delete_image(game->mlx, game->wall_img);
    mlx_delete_image(game->mlx, game->player_img);
    mlx_delete_image(game->mlx, game->moon_img);
    mlx_delete_image(game->mlx, game->btc_img);
}   

//

void   draw_gui(t_game *game)
{
    load_gui(game);
    print_map(game, game->map);
    player_pos(game);
    flood_fill(game, game->y_pos, game->x_pos);
}