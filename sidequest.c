/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sidequest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:34:20 by mafourni          #+#    #+#             */
/*   Updated: 2024/06/15 17:09:19 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

void	ft_free_all(char **map)
{
	int i;

	i = 0;
	while(map[i])
	{
		free(map[i]);
		map[i] = (0);
		i++;
	}
	free(map);
	map = (NULL);
}

t_all_the_time	*ft_innit(void)
{
	t_all_the_time *innit;

	innit = malloc(sizeof(t_all_the_time));
	if(!innit)
		return(0);
	innit->balade.i = 0;
	innit->check = 0;
	innit->balade.j = 0;
	innit->pidserv = 0;
	innit->pos_y_exit = 0;
	innit->pos_x_exit = 0;
	innit->move_count = 0;
	innit->balade.x = 0;
	innit->balade.nb_colum = 0;
	innit->balade.count = 0;
	innit->balade.len = 0;
	innit->balade.nb_line = 0;
	innit->checksoundniska = 0;
	innit->balade.count_check = 0;
	innit->pos_x_player = 0;
	innit->pos_y_player = 0;
	innit->count_collectible = 0;
	innit->balade.security = 0;
	innit->nb_collectible = 0;
	innit->count_collectible_ff = 0;
	innit->audioFile = NULL;
	innit->map = NULL;
	innit->map_copie = NULL;
	innit->mlx = NULL;
	return(innit);
}
t_stp	*ft_innit2(void)
{
	t_stp *innit;

	innit = malloc(sizeof(t_stp));
	if(!innit)
		return(0);
	innit->position_x_player_ff = 0;
	innit->positon_y_player_ff = 0;
	return(innit);
}
size_t	ft_strlensolong(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s [i] != '\n')
		i++;
	return (i);
}
void my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_all_the_time *all;
	all = param;
	ft_escape(keydata);
	if ((all->map[all->pos_y_player - 1][all->pos_x_player] != '1') && (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && (keydata.action == MLX_PRESS))
	{
		dothiswhenkeyup(all);
		all->pos_y_player--;
	}
	if ((all->map[all->pos_y_player + 1][all->pos_x_player] != '1') && (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && (keydata.action == MLX_PRESS))
	{
		dothiswhenkeydown(all);
		all->pos_y_player++;
	}
	if ((all->map[all->pos_y_player][all->pos_x_player + 1] != '1') && ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)) && (keydata.action == MLX_PRESS))
	{
		dothiswhenkeyright(all);
		all->pos_x_player++;
	}
	if ((all->map[all->pos_y_player][all->pos_x_player - 1] != '1') && (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && (keydata.action == MLX_PRESS))
	{
		dothiswhenkeyleft(all);
		all->pos_x_player--;
	}
}
