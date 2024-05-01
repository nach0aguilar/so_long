/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:12:45 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/01 12:13:06 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void check_extension(char *map)
{
    if (!map || ft_strncmp(map, ".ber", 4) != 0)
        return ;
}