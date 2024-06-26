/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:58:52 by igaguila          #+#    #+#             */
/*   Updated: 2024/04/17 20:05:56 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	**memory_clear(char **array, int words)
{
	while (words > -1)
	{
		free(array[words]);
		words--;
	}
	free(array);
	return (0);
}

static int	words(char const *s, char c)
{
	int	words;
	int	inword;
	int	i;

	words = 0;
	inword = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && inword == 0)
		{
			inword = 1;
			words++;
		}
		else if (s[i] == c)
			inword = 0;
		i++;
	}
	return (words);
}

static char	*make_word(char const *s, char c, int pos)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = pos;
	while (s[pos] && s[pos] != c)
		pos++;
	str = malloc(sizeof(char) * (pos - i + 1));
	if (!str)
		return (0);
	while (s[i] && s[i] != c)
		str[j++] = s[i++];
	str[j] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**array;

	i = 0;
	j = 0;
	array = (char **)malloc(sizeof(char *) * (words(s, c) + 1));
	if (!array || !s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			array[j] = make_word(s, c, i);
			if (!array[j])
				return (memory_clear(array, j));
			i += ft_strlen(array[j++]);
		}
	}
	array[j] = 0;
	return (array);
}
