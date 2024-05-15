/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:03:29 by npatron           #+#    #+#             */
/*   Updated: 2024/05/14 17:46:15 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

bool	empty_line(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

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

char	*copy_string_map(char *s, int n)
{
	char	*dest;
	int		i;
	int		j;

	dest = malloc(sizeof(char) * (n + 2) + 1);
	i = 1;
	j = 0;
	dest[0] = ' ';
	while (s[i])
	{
		dest[i] = s[j];
		i++;
		j++;
	}
	while (i <= (n + 1))
	{
		dest[i] = ' ';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	file_is_clean(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->start_line_map - 1)
	{
		if (is_texture(data, data->file[i]) == false && is_color(data, data->file[i]) == false
			&& empty_line(data->file[i]) == false)
			ft_exit(data, FILE_NO_CLEAN);
		i++;
	}
	return ;
}