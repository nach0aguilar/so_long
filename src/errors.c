/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:51:08 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/16 19:32:51 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Function to print an error message when the arguments are invalid

void	error_free(char *error, t_game *game)
{
	ft_putstr_fd(error, 2);
	if (game != NULL)
	{
		free_str(game->map);
		free_str(game->map_dup);
	}
	free(game);
	exit(EXIT_FAILURE);
}
