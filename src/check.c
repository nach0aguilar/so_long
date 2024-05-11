/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:12:45 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/11 17:54:32 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Function to check the extension of the map

void check_extension(char *map)
{
    char *extension;

    extension = ft_strrchr(map, '.');
    if (!extension || ft_strncmp(extension, ".ber", 4) != 0)
        error_argument("Error: Invalid extension\n");
}