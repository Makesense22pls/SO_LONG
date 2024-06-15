/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DIRECTIONKEYACTION.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 00:16:32 by mafourni          #+#    #+#             */
/*   Updated: 2024/06/15 19:22:27 by mafourni         ###   ########.fr       */
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
		system("killall afplay");
		exit(0);	
	}
}
void	fill(t_all_the_time *all, char **map_copie, size_t position_x, size_t position_y)
{
	int test = 0;
	ft_printf("LETSGO1\n");
	ft_printf("position_x[%d]\n", position_x);
	ft_printf("position_y[%d]\n", position_y);
	if (map_copie[position_y][position_x] == '1' || map_copie[position_y][position_x] == 'W')
		return;
	ft_printf("LETSGO2\n");
	if (position_y < 0 || position_y >= all->balade.nb_line || position_x < 0 || position_x >= all->balade.nb_colum)
		return;
	if (map_copie[position_y][position_x] == 'C')
	{
		ft_printf("IN\n\n");
		all->count_collectible_ff++;
	}
	map_copie[position_y][position_x] = 'W';
	while(map_copie[test] != NULL)
		printf("--[%s]--", map_copie[test++]);
	printf("\n\n");
	test = 0;
	while(all->map[test] != NULL)
		printf("++[%s]++", all->map[test++]);
	printf("\n\n");
	fill(all, map_copie, position_x , position_y - 1);
	fill(all, map_copie, position_x, position_y + 1);
	fill(all, map_copie, position_x - 1, position_y );
	fill(all, map_copie,position_x + 1, position_y);

}

int		flood_fill(t_all_the_time *all, t_stp *pls)
{
	int position_x_player;
	int position_y_player;
	int y;
	char **map_copie;
	map_copie = malloc(sizeof (char *) * (all->balade.nb_line + 1));
	y = 0;
	while(all->map[y] != NULL)
	{
		map_copie[y] = ft_strdup(all->map[y]);
		y++;
	}
	map_copie[y] = NULL;
	position_y_player = pls->positon_y_player_ff;
	position_x_player = pls->position_x_player_ff;
	fill(all, map_copie, position_x_player, position_y_player);
	if (all->nb_collectible != all->count_collectible_ff)
		return(EXIT_FAILURE);
	else
		return(EXIT_SUCCESS);
}
