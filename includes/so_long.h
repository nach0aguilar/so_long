/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:38:55 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/01 12:22:37 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <memory.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# define WIDTH 5120
# define HEIGHT 2880

typedef struct  s_game
{
    char        **map;
    
}               t_game;


// MAP //
t_game *pull_map(char *map);

#endif