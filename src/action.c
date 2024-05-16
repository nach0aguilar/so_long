/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:20:46 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/16 19:31:59 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	action(t_game *game, char **map, int x, int y)
{
	if (game->map[y][x] != '1')
	{
		if (game->map[y][x] == 'C')
			game->btc_counter++;
		if (game->map[y][x] == 'E')
		{
			if (game->btc_counter == game->btc_account)
				win_game(game);
			else
				return ;
		}
		game->map[game->y_pos][game->x_pos] = '0';
		img_floor_to_map(game, map, game->x_pos, game->y_pos);
		game->map[y][x] = 'P';
		game->y_pos = y;
		game->x_pos = x;
		game->mov_counter++;
		img_player_to_map(game, map, x, y);
		ft_printf("STEPS: %d | BTC: %d\n", game->mov_counter,
			game->btc_counter);
	}
}
