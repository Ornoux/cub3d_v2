/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:52:15 by npatron           #+#    #+#             */
/*   Updated: 2024/05/14 19:39:10 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	dda(t_data *data) //OK
{
	while (data->ray.hit == 0)
	{
		if (data->ray.side_x < data->ray.side_y)
		{
			data->ray.side_x += data->ray.delta_x;
			data->ray.mapx += data->ray.step_x;
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_y += data->ray.delta_y;
			data->ray.mapy += data->ray.step_y;
			data->ray.side = 1;
		}
		if (data->map[data->ray.mapx][data->ray.mapy] == '1')
			data->ray.hit = 1;
	}
}

void	init_step(t_data *data) //OK
{
	if (data->ray.dir_x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side_x = (data->p.pos_x - data->ray.mapx) * data->ray.delta_x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side_x = (data->ray.mapx + 1.0 - data->p.pos_x) * \
		data->ray.delta_x;
	}
	if (data->ray.dir_y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side_y = (data->p.pos_y - data->ray.mapy) * data->ray.delta_y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side_y = (data->ray.mapy + 1.0 - data->p.pos_y) * \
		data->ray.delta_y;
	}
}

void	init_values_rays(t_data *data, int i)
{
	ft_bzero(&data->ray, sizeof(t_ray));
	data->ray.camera_x = (2 * i) / (double)WIDTH - 1;
	data->ray.mapx = (int)data->p.pos_x;
	data->ray.mapy = (int)data->p.pos_y;
	data->ray.dir_x = data->p.dirp_x + (data->p.plane_x * data->ray.camera_x);
	data->ray.dir_y = data->p.dirp_y + (data->p.plane_y * data->ray.camera_x);
	if (data->ray.dir_x == 0)
		data->ray.delta_x = 1e30;
	else
		data->ray.delta_x = fabs(1 / data->ray.dir_x);
	if (data->ray.dir_y == 0)
		data->ray.delta_y = 1e30;
	else
		data->ray.delta_y = fabs(1 / data->ray.dir_y);
}

void	values_wall(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.perpendicular = (data->ray.side_x - data->ray.delta_x);
	else
		data->ray.perpendicular = (data->ray.side_y - data->ray.delta_y);
	if (data->ray.side)
		data->ray.wall_x = data->p.pos_x + \
		data->ray.perpendicular * data->ray.dir_x;
	else
		data->ray.wall_x = data->p.pos_y + \
		data->ray.perpendicular * data->ray.dir_y;
	data->ray.wall_x -= floor(data->ray.wall_x);
	data->ray.lineheight = (HEIGHT / data->ray.perpendicular);
	data->ray.start_draw = (-(data->ray.lineheight) / 2) + (HEIGHT / 2);
	data->ray.end_draw = ((data->ray.lineheight) / 2) + (HEIGHT / 2);
}

int	raycasting(t_data *data)
{
	int	i;

	i = 0;
	while (i <= WIDTH)
	{
		init_values_rays(data, i);
		init_step(data);
		dda(data);
		values_wall(data);
		build_column_2(data, i);
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img->img, 0, 0);
	return (0);
}
