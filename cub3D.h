/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:09:49 by npatron           #+#    #+#             */
/*   Updated: 2024/05/14 20:47:15 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"

# define WIDTH 1000
# define HEIGHT 400
# define MOVEMENT 0.2
# define ROTATION 0.2
# define PI 3.1415926
# define NO 1
# define SO 2
# define WE 3
# define EA 4

# define ARG "Error.\ncub3D needs to be launched with a '*.cub'."
# define FD "Error.\nFile cannot be open."
# define EMPTY_FILE "Error.\nFile is empty."
# define BAD_EXTENSION "Error.\nBad extension, please, run cub3D with a '*.cub'."
# define BAD_TEXTURES "Error.\nBad textures, the file needs [NO, SO, WE, EA] with paths."
# define BAD_COLORS "Error.\nBad colors, the file needs floor/sky color. Format : F/C X,X,X."
# define BAD_RANGE "Error.\nColors are RGB[0 - 255] for each."
# define MAP_ISNT_BOTTOM "Error.\nThe map isn't at the bottom of the file."
# define CLEAN_FILE "Error.\nPlease, clear this file.\nThe file needs 4 textures, 2 RGB colors, and a map."
# define NUMBER_MISSING "Error.\nIs missing numbers into your colors F/C"
# define  INVALID_CHAR_MAP "Error.\nThere is an invalid char into the map."
# define  NO_PLAYER "Error.\nThere is no/more than one player into the map"
# define MAP_NO_CLOSE "Error.\nThe map isn't close"
# define PLAYER_NO_CLOSE "Error.\nThere is no wall around the player"
# define FILE_NO_CLEAN "Error.\nThe file isn't clean."
# define XPM "Error.\nThe textures are not XPM"
# define NO_MAP "Error.\nThere is no map"
# define TEXTURE_INVALID "Error.\nTexture invalid"

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}			t_image;

typedef struct s_ray
{
	// Direction des rayons
	double	dir_x;
	double	dir_y;

	// DeltaX et DeltaY
	double	delta_x;
	double	delta_y;

	// Carre de la map
	int		mapx;
	int		mapy;

	// Longeur entre le prochain step
	double	side_x;
	double	side_y;

	// Step pour le DDA sur les bordures
	double	step_x;
	double	step_y;

	// 1 || 0 pour savoir durant le DDA si un mur est touche par le ray
	int		hit;

	// Side : NS || EW mur hit
	int		side;
	double	color_side;
	double	camera_x;

	//corrected dist
	double	perpendicular;
	double	lineheight;

	int		start_draw;
	int		end_draw;

	double	wall_x;

}				t_ray;

typedef struct s_p
{
	// Positions du joueur
	double	pos_x;
	double	pos_y;

	// Direction du player
	double	dirp_x;
	double	dirp_y;

	// Cam/Rota
	double	plane_x;
	double	plane_y;

	double	old_dir;
	double	old_plane;
}				t_p;




typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;

	char	player_direction;
	
	char	**file;
	char	**map;
	char	**textures;
	char	**colors;
	
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;

	char	*floor_path;
	char	*sky_path;

	int		no_texture;
	int		so_texture;
	int		ea_texture;
	int		we_texture;

	bool	floor_c;
	bool	sky_c;
	
	int		*sky_color;
	int		*floor_color;
	
	int		lines_into_file;
	int		max_len_line;
	int		start_line_map;
	int		last_line_map;
	int		nb_lines_map;

	int		player;
	int		posi_x;
	int		posi_y;
	
	int		tmp_x;
	int		tmp_y;
	
	int		*key;

	double rota;
	
	char	char_player;

	t_image	*img;
	t_image	*n;
	t_image	*s;
	t_image	*e;
	t_image	*w;
	t_ray	ray;
	t_p		p;
	
}			t_data;

// RAY_CASTING
void	init_raycast(t_data *data);
void	build_column_2(t_data *data, int x);
int		raycasting(t_data *data);
char	define_wallcolor(t_data *data);
int		choose_color(t_image *img, int x, int y);
void	set_floor(t_data *data, int x);
int		key_press(int key, t_data *data);
int		key_release(int key, t_data *data);
int		run_data(t_data *data);
int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	moves_forward_backward(t_data *data, int key);
void	moves_sides(t_data *data, int key);
void	moves_forward_backward_left(t_data *data, int key);


// MLX
int		init_my_texturess(t_data *data);
void	put_img(t_data *data, void	*img, int x, int y);
void	*ft_img(t_data *data, char *name);
void	init_mlx(t_data *data);
void	init(t_data *data);
int		mlx(t_data *data);
void	big_pixel_put(t_data *data, int x, int y, int color);
void	mini_map(t_data *data);
int		quit(t_data *data);


// PARSING
bool	is_texture(t_data *data, char *s);
bool	is_color(t_data *data, char *s);
void	get_file(t_data *data, char **argv);
int		launch_parsing(char **argv, t_data *data);
void	get_textures(t_data *data);
void	get_colors(t_data *data);
void	color_to_int(t_data *data);
void	parsing_map(t_data *data);
char	*copy_string_map(char *s, int n);
char	*line(int n);
void	is_valid_map(t_data *data);
void	file_is_clean(t_data *data);
int		ft_strlen_n(char *s);
void	free_struct(t_data *data);

// GET_NEXT_LINE PART

char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(char *src);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlen(const char *s);

// UTILS PART

char	*withoutSpaceAtBeginning(char *s);
void	ft_exit(t_data *data, char *s);
int		lines_into_files(char *argv);
void	free_char_tab(char **tab);
void	print_tab(char **tab);
void	print_int_tab(int *tab);
char	**ft_split(char const *s, char c);
int		big_atoi(const char *str);
bool	is_numeric(char c);
int		char_tab_len(char **tab);
void	find_max_len(t_data *data);
void	ft_bzero(void *s, size_t n);

#endif







