/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:51:08 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/11 21:13:16 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Function to print an error message when the arguments are invalid

void error_argument(char *error)
{
    ft_putstr_fd(error, 2);
    exit(EXIT_FAILURE);
}