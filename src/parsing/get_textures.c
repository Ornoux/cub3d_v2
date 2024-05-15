/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:22:48 by npatron           #+#    #+#             */
/*   Updated: 2024/05/14 21:46:24 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	texture_is_xpm(t_data *data, char *s)
{
	int	len;

	len = ft_strlen_n(s);
	if (s[len - 1] != 'm' || s[len - 2] != 'p'
		|| s[len - 3] != 'x' || s[len - 4] != '.')
		ft_exit(data, XPM);
	return ;
}

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
	{
		data->north_texture = s2;
		texture_is_xpm(data, data->north_texture);
	}
	else if ((s[0] == 'S' && s[1] == 'O') && (s[2] == ' ' || s[2] == '\t'))
	{
		data->south_texture = s2;
		texture_is_xpm(data, data->south_texture);
	}
	else if ((s[0] == 'W' && s[1] == 'E') && (s[2] == ' ' || s[2] == '\t'))
	{
		data->west_texture = s2;
		texture_is_xpm(data, data->west_texture);
	}
	else if ((s[0] == 'E' && s[1] == 'A') && (s[2] == ' ' || s[2] == '\t'))
	{
		data->east_texture = s2;
		texture_is_xpm(data, data->east_texture);
	}
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
	char	*tmp;

	i = 0;
	j = 0;
	data->textures = malloc(sizeof(char *) * 5);
	while (data->file[i])
	{
		tmp = withoutSpaceAtBeginning(data->file[i]);
		free(data->file[i]);
		data->file[i] = tmp;
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
		ft_exit(data, BAD_TEXTURES);
}
