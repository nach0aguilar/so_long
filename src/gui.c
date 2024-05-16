/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:47:31 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/16 19:33:23 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Function to load the images

void	load_gui(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./img/floor.png");
	game->floor_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./img/wall.png");
	game->wall_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./img/astronaut.png");
	game->player_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./img/exit.png");
	game->moon_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./img/bitcoin.png");
	game->btc_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}

// Function to delete the images

void	delete_gui(t_game *game)
{
	mlx_delete_image(game->mlx, game->floor_img);
	mlx_delete_image(game->mlx, game->wall_img);
	mlx_delete_image(game->mlx, game->player_img);
	mlx_delete_image(game->mlx, game->moon_img);
	mlx_delete_image(game->mlx, game->btc_img);
}

// Function to print the images

void	print_gui(t_game *game, char **map)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->rows)
	{
		col = 0;
		while (col < game->cols)
		{
			img_floor_to_map(game, map, col, row);
			img_wall_to_map(game, map, col, row);
			img_player_to_map(game, map, col, row);
			img_btc_to_map(game, map, col, row);
			img_moon_to_map(game, map, col, row);
			col++;
		}
		row++;
	}
}

// Function to load and draw the images

void	draw_gui(t_game *game)
{
	load_gui(game);
	print_gui(game, game->map);
	get_player_position(game);
	flood_fill(game, game->y_pos, game->x_pos);
	if (game->btc_account != game->btc_n || game->moon_account != game->moon_n)
		error_free("Error: The player cannot win on this map\n", game);
}
