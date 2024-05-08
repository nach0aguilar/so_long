/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:38:55 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/08 20:18:09 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 5120
# define HEIGHT 2880

typedef struct s_game
{
    mlx_t       mlx;
	char		**map;
	int			col;
	int			row;
	int			y_pos;
	int			x_pos;
	int			y_mov;
	int			x_mov;
	char		player;
	char		moon;
	char		btc;
	int			player_n;
	int			moon_n;
	int			btc_n;
	int			mov_n;
	mlx_image_t	player_img;
	mlx_image_t	btc_img;
	mlx_image_t	moon_img;
	mlx_image_t	floor_img;
	mlx_image_t	wall_img;

}				t_game;

// MAP //
t_game			*pull_map(char *map);

#endif