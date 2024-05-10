/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:22:48 by npatron           #+#    #+#             */
/*   Updated: 2024/05/10 18:23:55 by npatron          ###   ########.fr       */
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

bool	is_texture(char *s)
{
	s = withoutSpaceAtBeginning(s);
	if ((s[0] == 'N' && s[1] == 'O') && s[2] == ' ' || s[2] == '\t')
		return (true);
	else if ((s[0] == 'S' && s[1] == 'O') && s[2] == ' ' || s[2] == '\t')
		return (true);
	else if ((s[0] == 'W' && s[1] == 'E') && s[2] == ' ' || s[2] == '\t')
		return (true);
	else if ((s[0] == 'E' && s[1] == 'A') && s[2] == ' ' || s[2] == '\t')
		return (true);
	else
		return (false);
}

int	get_textures(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->file[i])
	{
		if (is_texture(data->file[i]) == true)
		{
			data->colors[j] = data->file[i];
			j++;
		}
		i++;		
	}
	
}