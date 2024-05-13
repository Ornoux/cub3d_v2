/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:09:49 by npatron           #+#    #+#             */
/*   Updated: 2024/05/14 00:38:28 by npatron          ###   ########.fr       */
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
# include <fcntl.h>
# include <stdbool.h>

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
typedef struct s_data
{
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
	
}			t_data;

// PARSING
bool	is_texture(t_data *data, char *s);
bool	is_color(t_data *data, char *s);
void	get_file(t_data *data, char **argv);
int		launch_parsing(char **argv, t_data *data);
void	get_textures(t_data *data);
void	get_colors(t_data *data);
void	color_to_int(t_data *data);
void	parsing_map(t_data *data);
void	number_into_path(char *s);
char	*fill_map_spaces(int n, char *s);
char	*space_line(t_data *data);



// GET_NEXT_LINE PART

char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(char *src);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlen(const char *s);

// UTILS PART

char	*withoutSpaceAtBeginning(char *s);
void	ft_exit(char *s);
int		lines_into_files(char *argv);
void	free_char_tab(char **tab);
void	print_tab(char **tab);
void	print_int_tab(int *tab);
char	**ft_split(char const *s, char c);
int		big_atoi(const char *str);
bool	is_numeric(char c);
int		char_tab_len(char **tab);
void	find_max_len(t_data *data);

#endif
