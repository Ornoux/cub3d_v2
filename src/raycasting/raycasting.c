/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:03:49 by npatron           #+#    #+#             */
/*   Updated: 2024/05/14 19:39:12 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

char	define_wallcolor(t_data *data)
{
	if (data->ray.dir_x <= 0 && data->ray.dir_y >= 0
		&& data->ray.side == 0)
		return ('N');
	else if (data->ray.dir_x <= 0 && data->ray.dir_y <= 0
		&& data->ray.side == 0)
		return ('N');
	else if (data->ray.dir_x >= 0 && data->ray.dir_y >= 0
		&& data->ray.side == 0)
		return ('S');
	else if (data->ray.dir_x >= 0 && data->ray.dir_y <= 0
		&& data->ray.side == 0)
		return ('S');
	else if (data->ray.dir_x <= 0 && data->ray.dir_y >= 0
		&& data->ray.side == 1)
		return ('E');
	else if (data->ray.dir_x >= 0 && data->ray.dir_y >= 0
		&& data->ray.side == 1)
		return ('E');
	return ('W');
}

int	choose_color(t_image *img, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = img->addr + (y * img->size_line + x * (img->bpp / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

void	set_floor(t_data *data, int x)
{
	int	y;

	y = data->ray.end_draw;
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(data, x, y, create_trgb(0, data->floor_color[0], \
		data->floor_color[1], data->floor_color[2]));
		y++;
	}
}
