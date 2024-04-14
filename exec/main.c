/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:06:04 by mafourni          #+#    #+#             */
/*   Updated: 2024/04/14 16:45:58 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(int argc, char **argv)
{
	t_all_the_time *evry;
	char **map;
	int i;

	i = 0;
	if (!(check_nb_arg(argc)) && !(check_ber(argv[1])))
		return (0);
	// printf("AVANTPRINT");
	evry = ft_peter();
	if (!(map = full_map(argv[1], evry)))
		return (0);
	if (!(check_len_char(map,evry)))
		return (0);
	// if (!(check_map_all_C(map)))
	// printf(" EVRY BALADE : %zu", evry->balade.count_line);
	// if (check_map_all_C(argv[1], map))
	// 	{
	// 		check_map_rectangle(map);
	// 	}
	// else 
	// 	return (0);
	// printf("GO");
	// printf("GO2");
	// printf("IN");
	// ft_free_all(map);
}