/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:20:46 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/15 20:17:16 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    action(t_game *game, int x, int y)
{
    if(game->map[y][x] != '1')
    {
        if(game->map[y][x] == 'C')
            game->btc_counter++;
        if(game->map[y][x] == 'E')
        {
            if (game->btc_counter == game->btc_account)
                win_game(game);
            else
                return ;
        }
        game->map[game->y_pos][game->x_pos] = '0';
        game->map[y][x] = 'P';
        game->y_pos = y;
        game->x_pos = x;
        game->mov_counter++;
        print_gui(game, game->map);
        ft_printf("STEPS: %d | BTC: %d\n", game->mov_counter, game->btc_counter);
    }
}
