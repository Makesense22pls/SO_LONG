/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:37:10 by mafourni          #+#    #+#             */
/*   Updated: 2024/04/25 17:31:38 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

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
		if (str == NULL)
			return(close(fd), i);
		// printf("%s\n\n\n", str);
		i++;
	}
	return (close(fd),i);
}

char **full_map(char *arg, t_all_the_time *evry)
{
	t_go draveil;
	int fd;
	
	evry->balade.count_line = 0;
	draveil.i = 0;
	// printf("%zu && %zu",draveil.i, evry->balade.x);
	if (ft_count_line(arg) == 0 || ft_count_line(arg) <= 2)
	{
		printf("ERROR, map INCCORECT");
		return (false);
	}
	evry->balade.count_line = ft_count_line(arg);
	fd = open(arg, O_RDONLY);
	evry->map = malloc(sizeof(char *) * (evry->balade.count_line + 1));
	if (!evry->map)
		return (free(evry->map),evry->map = NULL, NULL);
	while (draveil.i < evry->balade.count_line)
	{
		evry->map[draveil.i] = get_next_line(fd);
		// if evry->map[i][0] == '\n')
		// 	return (printf("UNE LIGNE VIDE\n"),(NULL));
		draveil.i++;
	}
	// printf("%zu", draveil.i);
	evry->map[evry->balade.count_line] = NULL;
	// printf(evry->map sans ligne vide\n");
	// printf("WESH %zu\n",evry->balade.count_line);
	return (close(fd),evry->map);
}

bool	check_len_char(char **map, t_all_the_time *evry)
{
	t_go lib;

	evry->balade.y = 0;
	lib.y = 0;
	// printf(" EVRY BALADE  dwdw : %zu", evry->balade.count_line);
	while(lib.y < evry->balade.count_line)
	{
		evry->balade.y = ft_strlensolong(map[lib.y]);
		// printf("CK%zu\n", evry->balade.y);
		if (lib.y > 0)
		{
			// printf("dans le if  STRLEN - 1: %zu\n", ft_strlensolong(map[lib.y - 1]));
			if (ft_strlensolong(map[lib.y - 1]) != evry->balade.y)
				{
					// printf("evry->balade.y dans le if%zu\n", evry->balade.y);
					// printf("dans le last if : %zu\n", ft_strlensolong(map[lib.y - 1]));
					printf("ERROR, SIZE MAP");
					return (false);
				}
		}
	lib.y ++;
	}
	if (check_map_all_C(map) == true)
		{
			printf("ALL CHAR\n");
			return (true);
		}
	else
		{
			printf("ERROR, WRONG CHAR\n");		
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
