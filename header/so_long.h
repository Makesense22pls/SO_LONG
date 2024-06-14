/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:14:18 by mafourni          #+#    #+#             */
/*   Updated: 2024/06/14 03:40:17 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include "MLX42/include/MLX42/MLX42.h"
#define TILE_SIZE 64

typedef struct s_go
{
	size_t i;
	size_t j;
	size_t x;
	size_t ycheh;
	size_t count;
	size_t len;
	size_t nb_line;
	size_t nb_colum;
	size_t count_check;
	size_t	security;
}t_go;

typedef struct s_pixel
{ 
	size_t x;
	size_t y;
	size_t px_player;
	size_t py_player;
	size_t px_collec;
	size_t py_collec;
	size_t px_exit;
	size_t py_exit;
	size_t px_floor;
	size_t py_floor;
	size_t px_wall;
	size_t py_wall;
}t_pixel;


typedef struct s_all_the_time
{
	t_go	balade;
	mlx_t 	*mlx;
	char	**map;
	size_t	pos_x_player;
	size_t	pos_y_player;
	int 	move_count;
	size_t	pos_x_exit;
	size_t  pos_y_exit;
	int check;
	size_t	nb_collectible;
	size_t	count_collectible;
	int		 checksoundniska;
	
	char *audioFile;
	pid_t pidserv;
	int		result;
	mlx_texture_t* texture_wall;
	mlx_texture_t* texture_perso;
	mlx_texture_t* texture_floor;
	mlx_texture_t* texture_exit;
	mlx_texture_t* texture_collec;
	mlx_texture_t* texture_final_exit;

	mlx_image_t* img_wall;
	mlx_image_t* img_perso;
	mlx_image_t* img_floor;
	mlx_image_t* img_exit;
	mlx_image_t* img_collec;
	mlx_image_t* img_final_exit;
}t_all_the_time;


t_all_the_time	*ft_innit(void);
void 	ft_escape(mlx_key_data_t keydata);
void	dothiswhenkeyleft(t_all_the_time *all);
void	dothiswhenkeyright(t_all_the_time *all);
void	dothiswhenkeyup(t_all_the_time *all);
void	dothiswhenkeydown(t_all_the_time *all);
void	print_final_window(t_all_the_time *all);
void	ft_final_sound(t_all_the_time *all);
void 	my_keyhook(mlx_key_data_t keydata, void* param);
void	chicken_sound_new_floor_and_player(t_all_the_time *all, size_t position_x_player, size_t position_y_player);
int 	putimage(t_all_the_time *all);
int		init_text_img(t_all_the_time *all);
bool	check_ber(char *str);
bool	check_nb_arg(int argc);
int		ft_count_line(char *arg);
char 	**full_map(char *arg, t_all_the_time *evry);
void	ft_free_all(char **map);
bool	check_map_all_C(char **map, t_all_the_time *evry);
char	*ft_strchrmap(const char *s, int c);
bool	check_len_char(char **map, t_all_the_time *evry);
size_t	ft_strlensolong(const char *s);
// CHECK MAP GOOD POSITION
bool 	check_map_place(char **map, t_all_the_time *evry);
bool	check_wall_line(char **map, t_all_the_time *evry);
bool	check_wall_collumn(char **map, t_all_the_time *evry);
bool	check_P_C_E(char **map, t_all_the_time *evry);