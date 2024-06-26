/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:14:41 by igaguila          #+#    #+#             */
/*   Updated: 2024/04/09 16:07:48 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char			*new;
	unsigned int	i;
	unsigned int	j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (0);
	new = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2)) + 1);
	if (!new)
		return (0);
	if (s1)
		while (s1[++i])
			new[i] = s1[i];
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = 0;
	free(s1);
	return (new);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int		i;
	char	*newstring;
	char	chr;

	i = 0;
	chr = (char)c;
	newstring = (char *)s;
	if (!s)
		return (0);
	if (c == '\0')
		return (newstring);
	while (s[i])
	{
		if (s[i] == chr)
			return (&newstring[i]);
		else
			i++;
	}
	if (newstring[i] == chr)
		return (&newstring[i]);
	return (0);
}
