/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:20:35 by npatron           #+#    #+#             */
/*   Updated: 2024/05/14 21:37:20 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	quit(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->n->img);
	mlx_destroy_image(data->mlx_ptr, data->s->img);
	mlx_destroy_image(data->mlx_ptr, data->e->img);
	mlx_destroy_image(data->mlx_ptr, data->w->img);
	mlx_destroy_image(data->mlx_ptr, data->img->img);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	free(data->n);
	free(data->s);
	free(data->e);
	free(data->w);
	free(data->img);
	free(data->key);
	free_struct(data);
	exit(0);
}

void	put_img(t_data *data, void	*img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img, x, y);
}

void	*ft_img(t_data *data, char *name)
{
	int		a;
	void	*new;

	new = mlx_xpm_file_to_image(data->mlx_ptr, name, &a, &a);
	if (!new)
		exit(0);
	return (new);
}

void	init_mlx(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIDTH, \
	HEIGHT, "cub3D");
	mlx_hook(data->mlx_win, 33, 1L << 17, quit, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, key_release, data);
	mlx_loop_hook(data->mlx_ptr, run_data, data);
	mlx_loop(data->mlx_ptr);
}

void	init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (init_my_texturess(data) == 1)
		ft_exit(data, TEXTURE_INVALID);
	data->img->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp, \
	&data->img->size_line, &data->img->endian);
	data->key = ft_calloc(6, sizeof(int));
}

int	mlx(t_data *data)
{
	data->img = ft_calloc(1, sizeof(t_image));
	data->n = ft_calloc(1, sizeof(t_image));
	data->s = ft_calloc(1, sizeof(t_image));
	data->w = ft_calloc(1, sizeof(t_image));
	data->e = ft_calloc(1, sizeof(t_image));
	init(data);
	init_mlx(data);
	return (0);
}
