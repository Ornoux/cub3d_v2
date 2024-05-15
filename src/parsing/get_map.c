/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:51:34 by npatron           #+#    #+#             */
/*   Updated: 2024/05/14 18:20:33 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	get_map(t_data *data)
{
	int		i;
	int		j;

	data->map = ft_calloc(sizeof(char *), ((data->lines_into_file - data->start_line_map) + 4));
	i = 1;
	j = data->start_line_map - 1;
	data->map[0] = line(data->max_len_line + 1);
	while (j < data->lines_into_file)
	{
		data->map[i] = copy_string_map(data->file[j], data->max_len_line + 1);
		i++;
		j++;
	}
	data->map[i] = line(data->max_len_line + 1);
	i++;
	data->map[i] = NULL;
}

bool	is_empty_line(char *s)
{
	if (s[0] == '\n')
		return (true);
	return (false);
}

bool	is_first_line_map(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n')
	{
		if (s[i] != '1' && s[i] != '0' && s[i] != 'N'
			&& s[i] != 'W' && s[i] != 'E' && s[i] != 'S'
			&& s[i] != ' ' && s[i] != '\t')
			return (false);
		i++;
	}
	return (true);
}

void	get_infos_map(t_data *data)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (data->file[i])
	{
		if (is_texture(data, data->file[i]) == true || is_color(data, data->file[i]) == true)
			count++;
		if (is_empty_line(data->file[i]) == false)
		{
			if (is_first_line_map(data->file[i]) == true)
			{
				data->start_line_map = i + 1;
				break;
			}
		}
		i++;
	}
	if (count < 6)
		ft_exit(data, MAP_ISNT_BOTTOM);
	else if (data->start_line_map == 0)
		ft_exit(data, NO_MAP);
	else
		return ;
}

void	parsing_map(t_data *data)
{
	get_infos_map(data);
	file_is_clean(data);
	find_max_len(data);
	get_map(data);
	is_valid_map(data);
}
