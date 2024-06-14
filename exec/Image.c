/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:51:53 by mafourni          #+#    #+#             */
/*   Updated: 2024/06/14 02:31:14 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"


int		putimage(t_all_the_time *all)
{
	t_pixel force;

	// int count = 0;
	int machinx;
	int machiny = 0;
    force.y = 0;
    while (all->map[force.y] != NULL)
    {
    	force.x = 0;
		machinx = 0;
        while (all->map[force.y][force.x])
        {
            if (all->map[force.y][force.x] == '1')
            {
                force.px_wall = machinx;
                force.py_wall = machiny;

                if (mlx_image_to_window(all->mlx, all->img_wall, force.px_wall, force.py_wall) < 0)
                    return(EXIT_FAILURE);
            }
			else if (all->map[force.y][force.x] == '0')
			{
				// printf("count = [%d]", ++count);
				force.px_floor = machinx;
                force.py_floor = machiny;

                if (mlx_image_to_window(all->mlx, all->img_floor, force.px_floor, force.py_floor) < 0)
                    return(EXIT_FAILURE);
			}
			else if (all->map[force.y][force.x] == 'P')
			{
				all->pos_x_player = force.x;
				all->pos_y_player = force.y;
				force.px_player = machinx;
                force.py_player = machiny;
			}
			else if (all->map[force.y][force.x] == 'C')
			{
				force.px_collec = machinx;
                force.py_collec = machiny;

                if (mlx_image_to_window(all->mlx, all->img_collec, force.px_collec, force.py_collec) < 0)
                    return(EXIT_FAILURE);
			}
			else if (all->map[force.y][force.x] == 'E')
			{
				// ft_printf("count = [%d]", ++count);
				force.px_exit = machinx;
                force.py_exit = machiny;

                if (mlx_image_to_window(all->mlx, all->img_exit, force.px_exit, force.py_exit) < 0)
                    return(EXIT_FAILURE);
			}
			machinx += TILE_SIZE;
            force.x++;
        }
		machiny += TILE_SIZE;
        force.y++;
    }
	if (mlx_image_to_window(all->mlx, all->img_floor, force.px_player, force.py_player) < 0)
        return(EXIT_FAILURE);
	if (mlx_image_to_window(all->mlx, all->img_perso, force.px_player, force.py_player) < 0)
        return(EXIT_FAILURE);
	return(EXIT_SUCCESS);
}
int	init_text_img(t_all_the_time *all)
{
	all->texture_wall = mlx_load_png("textures/WALL.png");
	all->texture_perso = mlx_load_png("textures/PLAYER.png");
	all->texture_floor = mlx_load_png("textures/FLOOR.png");
	all->texture_exit = mlx_load_png("textures/EXIT.png");
	all->texture_collec = mlx_load_png("textures/COLLEC.png");
	all->texture_final_exit = mlx_load_png("textures/FINAL_EXIT.png");
	if (!all->texture_wall || !all->texture_final_exit || !all->texture_perso || !all->texture_floor || !all->texture_exit || !all->texture_collec )
		return(EXIT_FAILURE);
	all->img_wall = mlx_texture_to_image(all->mlx, all->texture_wall);
	all->img_perso = mlx_texture_to_image(all->mlx, all->texture_perso);
	all->img_floor = mlx_texture_to_image(all->mlx, all->texture_floor);
	all->img_exit = mlx_texture_to_image(all->mlx, all->texture_exit);
	all->img_collec = mlx_texture_to_image(all->mlx, all->texture_collec);
	all->img_final_exit = mlx_texture_to_image(all->mlx, all->texture_final_exit);
	if (!all->img_wall || !all->img_final_exit ||!all->img_perso || !all->img_floor || !all->img_exit || !all->img_collec)
		return(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}