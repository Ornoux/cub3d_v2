/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:19:58 by npatron           #+#    #+#             */
/*   Updated: 2024/05/15 14:28:05 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

char	*erase_bck_n(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			s[i] = '\0';
		i++;
	}
	return (ft_strdup(s));
}

int	init_my_texturess(t_data *data)
{
	data->north_texture = erase_bck_n(data->north_texture);
	data->south_texture = erase_bck_n(data->south_texture);
	data->west_texture = erase_bck_n(data->west_texture);
	data->east_texture = erase_bck_n(data->east_texture);

	data->n->img = mlx_xpm_file_to_image(data->mlx_ptr, data->north_texture, \
	&data->n->width, &data->n->height);
	// if (!data->n->img)
	// 	return (1);
	data->n->addr = mlx_get_data_addr(data->n->img, &data->n->bpp, \
	&data->n->size_line, &data->n->endian);
	data->s->img = mlx_xpm_file_to_image(data->mlx_ptr, data->south_texture, \
	&data->s->width, &data->s->height);
	// if (!data->s->img)
	// 	return (1);
	data->s->addr = mlx_get_data_addr(data->s->img, &data->s->bpp, \
	&data->s->size_line, &data->s->endian);
	data->w->img = mlx_xpm_file_to_image(data->mlx_ptr, data->west_texture, \
	&data->w->width, &data->w->height);
	// if (!data->w->img)
	// 	return (1);
	data->w->addr = mlx_get_data_addr(data->w->img, &data->w->bpp, \
	&data->w->size_line, &data->w->endian);
	data->e->img = mlx_xpm_file_to_image(data->mlx_ptr, data->east_texture, \
	&data->e->width, &data->e->height);
	// if (!data->e->img)
	// 	return (1);
	data->e->addr = mlx_get_data_addr(data->e->img, &data->e->bpp, \
	&data->e->size_line, &data->e->endian);
	return (0);
}
