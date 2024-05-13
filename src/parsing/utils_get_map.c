/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:03:29 by npatron           #+#    #+#             */
/*   Updated: 2024/05/14 00:39:48 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	find_max_len(t_data *data)
{
	int	i;
	int	len;
	
	i = data->start_line_map;
	len = 0;
	while (data->file[i])
	{
		if (ft_strlen(data->file[i]) > len)
			len = ft_strlen(data->file[i]);
		i++;
	}
	data->max_len_line = len;
}

char	*line(int n)
{
	int		i;
	char	*s;

	i = 0;
	s = malloc(sizeof(char) * (n + 3));
	while (i != n + 1)
	{
		s[i] = ' ';
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*fill_map_spaces(int n, char *s)
{
	char	*dest;
	int		i;
	int		j;

	dest = malloc(sizeof(char) * (n + 2) + 1);
	i = 1;
	j = 0;
	dest[0] = 'P';
	while (s[i])
	{
		dest[i] = s[j];
		i++;
		j++;
	}
	while (i <= (n + 1))
	{
		dest[i] = 'P';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*space_line(t_data *data)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * (data->max_len_line + 3));
	while (i < data->max_len_line)
	{
		res[i] = 'P';
		i++;
	}
	res[i] = '\0';
	return (res);
}