/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:51:34 by npatron           #+#    #+#             */
/*   Updated: 2024/05/12 21:37:06 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

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
				data->start_line_map = i;
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
}
