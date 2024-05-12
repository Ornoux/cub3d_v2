/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:22:48 by npatron           #+#    #+#             */
/*   Updated: 2024/05/12 22:58:48 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

bool	is_color(t_data *data, char *s)
{
	if (s[0] == 'F' && (s[1] == ' ' || s[1] == '\t'))
	{
		data->floor_c = true;
		return (true);
	}
	else if (s[0] == 'C' && (s[1] == ' ' || s[1] == '\t'))
	{
		data->sky_c = true;
		return (true);
	}

	else
		return (false);
}

void	attribute_colors(t_data *data, char *s, char *s2)
{
	if (s[0] == 'F' && (s[1] == ' ' || s[1] == '\t'))
		data->floor_path = ft_strdup(s2);
	else if (s[0] == 'C' && (s[1] == ' ' || s[1] == '\t'))
		data->sky_path = ft_strdup(s2);
	else
		return ;
}

void	getPathsColors(t_data *data)
{
	int		i;
	int		j;
	char	*tmp;
	
	i = 0;
	while (data->colors[i])
	{
		j = 1;
		tmp = withoutSpaceAtBeginning(data->colors[i]);
		free(data->colors[i]);
		data->colors[i] = tmp;
		while (data->colors[i][j] == ' ' || data->colors[i][j] == '\t')
			j++;
		attribute_colors(data, data->colors[i], data->colors[i] + j);
		i++;
	}
	return ;
}

void	get_colors(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->colors = malloc(sizeof(int *) * 3);
	while (data->file[i])
	{
		if (is_color(data, data->file[i]) == true)
		{
			data->colors[j] = ft_strdup(data->file[i]);
			j++;
		}
		i++;
	}
	data->colors[j] = NULL;
	if (data->floor_c == true && data->sky_c == true)
	{
		getPathsColors(data);
		free_char_tab(data->colors);
		return ;
	}
	else
		ft_exit(BAD_COLORS);
}
