/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:10:49 by npatron           #+#    #+#             */
/*   Updated: 2024/05/11 18:28:34 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static int	count_words(char const *s, char c)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i] != '\0')
			&& (s[i + 1] == c || s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static char	*copy_string(char const *s, char c, int i)
{
	char	*copy;
	int		j;
	int		k;
	int		len;

	j = i;
	k = 0;
	while (s[j] && s[j] != c)
		j++;
	len = j - i;
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	while (k < len)
	{
		copy[k] = s[i];
		k++;
		i++;
	}
	copy[k] = '\0';
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = malloc((sizeof (char *)) * ((count_words(s, c)) + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			dest[j] = copy_string(s, c, i);
			j++;
		}
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	dest[j] = 0;
	return (dest);
}