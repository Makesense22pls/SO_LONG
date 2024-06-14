/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:06:04 by mafourni          #+#    #+#             */
/*   Updated: 2024/06/14 02:30:10 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

int main(int argc, char **argv)
{
	t_all_the_time *all;

	int i;
	i = 0;
	if (!(check_nb_arg(argc)) || !(check_ber(argv[1])))
		return (0);
	all = ft_innit();
	if (!(full_map(argv[1], all)))
	{
		if (all->map)
			ft_free_all(all->map);
		return (0);
	}
	if (!(check_len_char(all->map,all)) || !(check_map_place(all->map, all)))
	{
		if (all->map)
			ft_free_all(all->map);
		return (0);	
	}
	i = 0;
	ft_printf("YA NULL[--%s--]\n",all->map[4]);
	all->mlx = mlx_init(all->balade.nb_colum * 64 ,all->balade.nb_line * 64 ,"./so_long",false);
	if(!all->mlx)
		return(EXIT_FAILURE);
	init_text_img(all);
	putimage(all);
	mlx_key_hook(all->mlx, &my_keyhook, all);
	mlx_loop(all->mlx);
	mlx_terminate(all->mlx);
	system("killall afplay");
	return (EXIT_SUCCESS);
}
