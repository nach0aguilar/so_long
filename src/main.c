/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:38:32 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/04 11:46:22 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/ft_printf/ft_printf.h"

int main (int argc, char **argv)
{
	// t_game **game;

	// if (argc == 1 || (argc == 2 && !argv[1]))
	// 	return (0);
	// check_extension(argv[1]);
	// game = pull_map(argv[1]);
	if(argc == 1 && !argv[1])
		ft_printf("Hola");
	return 0;
}