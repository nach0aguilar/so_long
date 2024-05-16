/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:38:32 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/16 21:40:19 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 1 || (argc == 2 && !argv[1]))
		return (ft_putstr_fd("Error: There is only one argument", 2), 0);
	if (argc > 2)
		return (ft_putstr_fd("Error: There are more than two arguments", 2), 0);
	game = pull_map(argv[1]);
	check_extension(argv[1], game);
	check_rectangle(game);
	check_walls(game);
	check_invalid_char(game);
	init_game(game);
}
