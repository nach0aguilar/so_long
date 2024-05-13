/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:57:26 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/13 17:14:09 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int32_t init_game(t_game *game)
{
    game->mlx = mlx_init(64 * game->cols, 64 * game->rows, "so_long", false);
    if (!game->mlx)
        error_argument("Error: Failed to initialize game\n");
    load_gui(game);
    return (1);
}