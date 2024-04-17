/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:06:04 by mafourni          #+#    #+#             */
/*   Updated: 2024/04/16 20:34:59 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_all_the_time *evry;
	mlx_t*	mlx;

	int i;

	i = 0;
	if (!(check_nb_arg(argc)) || !(check_ber(argv[1])))
		return (0);
	// printf("AVANTPRINT");
	evry = ft_peter();
	if (!(full_map(argv[1], evry)))
	{
		if (evry->map)
			ft_free_all(evry->map);
		return (0);
	}
	// printf("AVANTPRINT");
	if (!(check_len_char(evry->map,evry)) || !(check_map_place(evry->map, evry)))
		{
			if (evry->map)
				ft_free_all(evry->map);
			return (0);	
		}
	while(evry->map[i] != NULL)
		{
			free(evry->map[i]);
			i++;
		}
	free(evry->map);
	free(evry);
	mlx = mlx_init(WIDTH,HEIGHT,"./so_long",true);
	if(!mlx)
		return(EXIT_FAILURE);
	mlx_texture_to_image()
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
