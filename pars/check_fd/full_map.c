/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:37:10 by mafourni          #+#    #+#             */
/*   Updated: 2024/04/14 16:46:40 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchrmap(const char *s, int c)
{
	unsigned char	c_;
	unsigned char	*s_;

	c_ = (unsigned char) c;
	s_ = (unsigned char *) s;
	if (s == NULL)
		return (0);
	if (c_ == '\0')
	{
		while (*s_ != '\0')
			s_++;
		return ((char *)(s_));
	}
	while (*s_ != '\0')
	{
		if (*s_ == c_)
			return ((char *)(s_));
		s_++;
	}
	return (0);
}

int	ft_count_line(char *arg)
{
	int i = 0;
	// int check = 0;
	int fd;
	char *str;
	fd = open(arg, O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s\n", str);
		i++;
	}
	return (close(fd),i);
}

char **full_map(char *arg, t_all_the_time *evry)
{
	t_go draveil;
	char **map;
	int fd;
	
	evry->balade.count_line = 0;
	draveil.i = 0;
	// printf("%zu && %zu",draveil.i, evry->balade.x);
	evry->balade.count_line = ft_count_line(arg);
	fd = open(arg, O_RDONLY);
	map = malloc(sizeof(char *) * (evry->balade.count_line + 1));
	if (!map)
		return (free(map), map = NULL, NULL);
	while (draveil.i < evry->balade.count_line)
	{
		map[draveil.i] = get_next_line(fd);
		// if (map[i][0] == '\n')
		// 	return (printf("UNE LIGNE VIDE\n"),(NULL));
		draveil.i++;
	}
	// printf("%zu", draveil.i);
	map[evry->balade.count_line] = NULL;
	// printf("MAP sans ligne vide\n");
	printf("WESH %zu\n",evry->balade.count_line);
	return (close(fd),map);
}

bool	check_len_char(char **map, t_all_the_time *evry)
{
	t_go lib;
	size_t count_check;

	count_check = 0;
	lib.y = 0;
	// printf(" EVRY BALADE  dwdw : %zu", evry->balade.count_line);
	while(lib.y < evry->balade.count_line)
	{
		count_check = ft_strlensolong(map[lib.y]);
		printf("CK%zu\n", count_check);
		if (lib.y > 0)
		{
			printf("dans le if  STRLEN - 1: %zu\n", ft_strlensolong(map[lib.y - 1]));
			if (ft_strlensolong(map[lib.y - 1]) != count_check)
				{
					printf("count_check dans le if%zu\n", count_check);
					printf("dans le last if : %zu\n", ft_strlensolong(map[lib.y - 1]));
					printf("PAS SAME LEN");
					return (false);
				}
		}
	lib.y ++;
	}
	if (check_map_all_C(map) == true)
		{
			printf("C GOOD");
			return (true);
		}
	else
		{
			printf("ERROR, WRONG SIZE OR WRONG CHAR");		
			return (false);
		}
	// printf ("AKSKIP CA MARCHE SAME LEN");
}
bool	check_map_all_C(char **map)
{
	t_go lib;

	lib.y = 0;
	while (map[lib.y]!= NULL)
	{
		lib.x = 0;
		while(map[lib.y][lib.x]!= '\0')
		{
			if (!(ft_strchrmap("10EPC\n", map[lib.y][lib.x])))
				return (false);
			lib.x ++;
		}
		lib.y ++;
	}
	return (true);
}

// bool	check_map_rectangle(char **map, t_go *la_puuuuu)
// {
// 	while (map[la_puuuuu->y] != NULL)
// 		la_puuuuu.y ++;
// 	y = 0;
// 	while (y < count)
// 	{	
		
// 		x = ft_strlen(map[y]);
// 		if (y < count)
// 			{
// 				len = ft_strlen(map[count - 1]);
// 				printf("len : %zu\n", len);
// 				printf("count -1 %s\n", map[count -1]);
// 				if (len != x)
// 					return (printf("PAS UN RECTANGLE", false));
// 			}
// 		y++;
// 	}
// 	printf("C'EST UN RECTANGLE\n");
// 	return (true);
// }
// bool	check_one( char **map)
// {
// 	size_t x;
// 	size_t y;

// 	x = 0;
// 	y = 0;
// 	while (map)
// }

// bool	checkallCchar (char *arg, char **map, t_all_the_time *evry)
// {
// 	t_go lib;

// 	lib.y = 0;
// 	while (map[lib.y] != NULL)
// 	{
// 		lib.x = 0;
// 		while (map[lib.y][lib.x] != '\0')
// 		{
// 			if(!(ft_strchrmap("10EPC\n", map[lib.y][lib.x])))
// 			{
// 				printf("CAMARCHEPAS\n");
// 				return (false);
// 			}
// 		}
// 	}
// }


