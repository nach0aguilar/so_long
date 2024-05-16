/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:14:43 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/16 19:33:03 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Function to free the map

void	free_str(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

// Function to win the game

void	win_game(t_game *game)
{
	ft_printf("CONGRATULATIONS! YOU HAVE WON IN %d STEPS", game->mov_counter);
	delete_gui(game);
	free_str(game->map);
	free_str(game->map_dup);
	mlx_terminate(game->mlx);
	free(game);
	exit(EXIT_SUCCESS);
}

// Function to close the game

void	close_game(t_game *game)
{
	ft_printf("YOU HAVE CLOSED THE GAME\n");
	delete_gui(game);
	free_str(game->map);
	free_str(game->map_dup);
	mlx_terminate(game->mlx);
	free(game);
	exit(EXIT_SUCCESS);
}
