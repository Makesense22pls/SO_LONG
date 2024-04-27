/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:51:53 by mafourni          #+#    #+#             */
/*   Updated: 2024/04/22 14:25:22 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	ft_affiche(void)
{
	mlx_t*	mlx;
	mlx = mlx_init(WIDTH,HEIGHT,"./so_long",true);
	if(!mlx)
		return(EXIT_FAILURE);
	ft_tema(mlx);
	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	if (!img)
        return(EXIT_FAILURE);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        return(EXIT_FAILURE);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
}

int ft_tema(mlx)
{
	mlx_texture_t* FLOOR = mlx_load_png("textures/FLOOR.png");
	if(!FLOOR)
		return(EXIT_FAILURE);
	mlx_texture_t* PLAYER = mlx_load_png("textures/PLAYER.png");
	if(!PLAYER)
		return(EXIT_FAILURE);
	mlx_texture_t* WALL = mlx_load_png("textures/WALL.png");
	if(!WALL)
		return(EXIT_FAILURE);
	mlx_texture_t* COLLECT = mlx_load_png("textures/COLLECT.png");
	if(!COLLECT)
		return(EXIT_FAILURE);
	mlx_texture_t* EXIT = mlx_load_png("textures/EXIT.png");
	if(!EXIT)
		return(EXIT_FAILURE);
}