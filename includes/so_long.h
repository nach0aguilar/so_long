/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:38:55 by igaguila          #+#    #+#             */
/*   Updated: 2024/04/30 19:23:37 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include "../MLX42/include/MLX42/MLX42.h"
#define WIDTH 5120
#define HEIGHT 2880

typedef struct  s_game
{
    char **map;
    
}               t_game;


#endif