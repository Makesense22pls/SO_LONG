/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DIRECTIONKEYACTION.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 00:16:32 by mafourni          #+#    #+#             */
/*   Updated: 2024/06/14 04:19:53 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

void	dothiswhenkeyup(t_all_the_time *all)
{
	int copie_x = 0;
	int copie_y = 0;
	ft_printf(" Movement count = [%d]\n", all->move_count++);
	all->img_perso->instances[all->count_collectible].y -= 64;
	if (all->map[all->pos_y_player - 1][all->pos_x_player] == 'E' && all->check == 1)
	{
		system("killall afplay");
		exit(0);
	}	
	if (all->map[all->pos_y_player - 1][all->pos_x_player] == 'C')
	{
		system("killall afplay");
		all->pidserv = fork();
		copie_x = all->pos_x_player;
		copie_y = all->pos_y_player;
		chicken_sound_new_floor_and_player(all,copie_x, (copie_y - 1));
	}
	print_final_window(all);
}

void	dothiswhenkeydown(t_all_the_time *all)
{
	int copie_x = 0;
	int copie_y = 0;
	ft_printf(" Movement count = [%d]\n", all->move_count++);
	all->img_perso->instances[all->count_collectible].y += 64;
	if (all->map[all->pos_y_player + 1][all->pos_x_player] == 'E' && all->check == 1)
	{
		system("killall afplay");	
		exit(0);
	}	
	if (all->map[all->pos_y_player + 1][all->pos_x_player] == 'C')
	{
		system("killall afplay");
		all->pidserv = fork();
		copie_x = all->pos_x_player;
		copie_y = all->pos_y_player;
		chicken_sound_new_floor_and_player(all,copie_x, (copie_y + 1));
	}
	print_final_window(all);
}

void	dothiswhenkeyleft(t_all_the_time *all)
{
	int copie_x = 0;
	int copie_y = 0;
	ft_printf(" Movement count = [%d]\n", all->move_count++);
	all->img_perso->instances[all->count_collectible].x -= 64;
	if (all->map[all->pos_y_player][all->pos_x_player - 1] == 'E' && all->check == 1)
	{
		system("killall afplay");
		exit(0);
	}	
	if (all->map[all->pos_y_player][all->pos_x_player - 1] == 'C')
	{
		system("killall afplay");
		all->pidserv = fork();
		copie_x = all->pos_x_player;
		copie_y = all->pos_y_player;
		chicken_sound_new_floor_and_player(all, (copie_x - 1), copie_y);
	}
	print_final_window(all);
}

void	dothiswhenkeyright(t_all_the_time *all)
{
	int copie_x = 0;
	int copie_y = 0;
	all->img_perso->instances[all->count_collectible].x += 64;
	if (all->map[all->pos_y_player][all->pos_x_player + 1] == 'E' && all->check == 1)
	{
		system("killall afplay");
		exit(0);
	}	
	if (all->map[all->pos_y_player][all->pos_x_player + 1] == 'C')
	{
		system("killall afplay");
		all->pidserv = fork();
		copie_x = all->pos_x_player;
		copie_y = all->pos_y_player;
		chicken_sound_new_floor_and_player(all, (copie_x + 1), copie_y);
	}
	print_final_window(all);
}
void ft_escape(mlx_key_data_t keydata)
{
	if(keydata.key == MLX_KEY_ESCAPE)
	{
		exit(0);	
		system("killall afplay");
	}
}