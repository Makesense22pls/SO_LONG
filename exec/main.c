/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:06:04 by mafourni          #+#    #+#             */
/*   Updated: 2024/04/07 19:39:47 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	char **map;
	int i;

	i = 0;
	if (!(check_nb_arg(argc)))
		return (0);
	if (!(check_ber(argv[1])))
		return (0);
	map = full_map(argv[1]);
	// while (map[i] != NULL)
	// 	{
	// 		ft_printf("%s", map[i]);  AFFICHER LA MAP;
	// 		i ++;
	// 	}
	check_map_all_C(argv[1], map);
	ft_free_all(map);
}