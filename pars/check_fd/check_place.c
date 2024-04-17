/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:31:19 by mafourni          #+#    #+#             */
/*   Updated: 2024/04/15 15:46:45 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool check_map_place(char **map, t_all_the_time *evry)
{
	if (!(check_wall_line(map, evry)) && !(check_wall_collumn(map,evry)))
	{
		printf("MAP MAL FERMÉ\n");
		return (false);
	}
	if (!(check_P_C_E(map, evry)))
	{
		// printf("ELEMENTS MANQUANTS\n");
		return (false);
	}
	return (true);
}

bool	check_wall_line(char **map, t_all_the_time *evry)
{
	t_go lib;

	lib.i = 0;
	while (lib.i < evry->balade.y)
	{
		if (!(ft_strchrmap("1", map[0][lib.i])))
			return (false);
		if (!(ft_strchrmap("1", map[evry->balade.count_line - 1][lib.i])))
			return (false);
		lib.i ++;
	}
	printf("ONLY 1 in LINE \n");
	return (true);
}

bool	check_wall_collumn(char **map, t_all_the_time *evry)
{
	t_go lib;

	lib.i = 0;
	while (lib.i < evry->balade.count_line)
	{
		if (!(ft_strchrmap("1", map[lib.i][0])))
			return (false);
		if (!(ft_strchrmap("1", map[lib.i][evry->balade.y])))
			return (false);
		lib.i++;
	}
	printf("ONLY 1 in COLUMN \n");
	return(true);
}
bool	check_P_C_E(char **map, t_all_the_time *evry)
{
	t_go lib;

	lib.y = 0;
	lib.count = 0;
	int letters[128] = {0};
	while (lib.y < evry->balade.count_line)
	{
		lib.x = 0;
		while(lib.x < evry->balade.y)
		{
			if(map[lib.y][lib.x] == 'P' || map[lib.y][lib.x] == 'C' || map[lib.y][lib.x] == 'E')
				letters[(int)map[lib.y][lib.x]] = 1;
			if(map[lib.y][lib.x] == 'P' || map[lib.y][lib.x] == 'E')
				lib.count++;
			lib.x ++;
		}
		lib.y++;
	}
	if (letters[80] != 1 || letters[67] != 1 || letters[69] != 1)
		return (printf("ELEMENTS MAQUANTS"),false);
	if (lib.count > 2)
		return(printf("ERROR DOUBLON"), false);
	printf("ALL ELLEMENTS THERE\n");
	return (true);
}