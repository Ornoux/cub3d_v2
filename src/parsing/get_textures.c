/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:22:48 by npatron           #+#    #+#             */
/*   Updated: 2024/05/12 22:08:59 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

char	*withoutSpaceAtBeginning(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	return (ft_strdup(s + i));
}

bool	is_texture(t_data *data, char *s)
{
	if ((s[0] == 'N' && s[1] == 'O') && (s[2] == ' ' || s[2] == '\t'))
	{
		data->no_texture++;
		return (true);
	}
	else if ((s[0] == 'S' && s[1] == 'O') && (s[2] == ' ' || s[2] == '\t'))
	{
		data->so_texture = true;
		return (true);
	}
	else if ((s[0] == 'W' && s[1] == 'E') && (s[2] == ' ' || s[2] == '\t'))
	{
		data->we_texture++;
		return (true);
	}
	else if ((s[0] == 'E' && s[1] == 'A') && (s[2] == ' ' || s[2] == '\t'))
	{
		data->ea_texture++;
		return (true);
	}
	else
		return (false);
}

void	attribute_texture(t_data *data, char *s, char *s2)
{
	if ((s[0] == 'N' && s[1] == 'O') && (s[2] == ' ' || s[2] == '\t'))
		data->north_texture = ft_strdup(s2);
	else if ((s[0] == 'S' && s[1] == 'O') && (s[2] == ' ' || s[2] == '\t'))
		data->south_texture = ft_strdup(s2);
	else if ((s[0] == 'W' && s[1] == 'E') && (s[2] == ' ' || s[2] == '\t'))
		data->west_texture = ft_strdup(s2);
	else if ((s[0] == 'E' && s[1] == 'A') && (s[2] == ' ' || s[2] == '\t'))
		data->east_texture = ft_strdup(s2);
	else
		return ;
}

void	getPathsTextures(t_data *data)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (data->textures[i])
	{
		j = 2;
		tmp = withoutSpaceAtBeginning(data->textures[i]);
		free(data->textures[i]);
		data->textures[i] = tmp;
		while (data->textures[i][j] == ' ' || data->textures[i][j] == '\t')
			j++;
		attribute_texture(data, data->textures[i], data->textures[i] + j);
		i++;
	}
	return ;
}

void	get_textures(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	data->textures = malloc(sizeof(char *) * 5);
	while (data->file[i])
	{
		if (is_texture(data, data->file[i]) == true)
		{
			data->textures[j] = ft_strdup(data->file[i]);
			j++;
		}
		i++;
	}
	data->textures[j] = NULL;
	if (data->no_texture == 1 && data->ea_texture == 1 && data->we_texture == 1 &&
		data->so_texture == 1)
	{
		getPathsTextures(data);
		free_char_tab(data->textures);
		return ;
	}
	else
		ft_exit(BAD_TEXTURES);
}
