/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:51:34 by npatron           #+#    #+#             */
/*   Updated: 2024/05/14 00:41:29 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	get_map(t_data *data)
{
	int	len_map;
	int i;
	int	j;
	
	i = data->start_line_map - 1;
	j = 1;
	len_map = data->lines_into_file - data->start_line_map + 2;
	data->map = malloc(sizeof(char *) * len_map + 2);
	data->map[0] = space_line(data);
	while (data->file[i] && i < len_map)
	{
		data->map[j] = fill_map_spaces(data->max_len_line, data->file[i]);
		printf("%s", data->map[j]);
		i++;
		j++;
	}
	j++;
	data->map[j] = space_line(data);
	j++;
	data->map[j] = NULL;
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
		if (s[i] != '1')
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
		ft_exit(MAP_ISNT_BOTTOM);
	else if (count > 6)
		ft_exit(CLEAN_FILE);
	else
		return ;
}

void	parsing_map(t_data *data)
{
	get_infos_map(data);
	find_max_len(data);
	get_map(data);
	printf("\n\n\n\n");
	print_tab(data->map);

}
