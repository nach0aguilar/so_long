/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:45:05 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/16 19:33:53 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Functions to define the player's movements

static void	up(t_game *game)
{
	action(game, game->map, game->x_pos, game->y_pos - 1);
}

static void	left(t_game *game)
{
	action(game, game->map, game->x_pos - 1, game->y_pos);
}

static void	down(t_game *game)
{
	action(game, game->map, game->x_pos, game->y_pos + 1);
}

static void	right(t_game *game)
{
	action(game, game->map, game->x_pos + 1, game->y_pos);
}

// Function to move the player

void	movements(mlx_key_data_t paramkey, t_game *game)
{
	if (paramkey.key == MLX_KEY_W && paramkey.action == MLX_PRESS)
		up(game);
	else if (paramkey.key == MLX_KEY_A && paramkey.action == MLX_PRESS)
		left(game);
	else if (paramkey.key == MLX_KEY_S && paramkey.action == MLX_PRESS)
		down(game);
	else if (paramkey.key == MLX_KEY_D && paramkey.action == MLX_PRESS)
		right(game);
	else if (paramkey.key == MLX_KEY_ESCAPE && paramkey.action == MLX_PRESS)
		close_game(game);
	if (paramkey.action != MLX_PRESS)
		return ;
}
