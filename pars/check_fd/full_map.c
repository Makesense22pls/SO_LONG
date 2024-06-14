/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:37:10 by mafourni          #+#    #+#             */
/*   Updated: 2024/06/13 19:26:50 by mafourni         ###   ########.fr       */
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
	int fd;
	char *str;
	fd = open(arg, O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		if (str == NULL)
			return(close(fd), i);
		i++;
	}
	printf("value of i plslsls [%d]\n", i);
	return (close(fd),i);
}

char **full_map(char *arg, t_all_the_time *evry)
{
	t_go draveil;
	int fd;

	evry->balade.nb_line = 0;
	draveil.i = 0;
	if (ft_count_line(arg) == 0 || ft_count_line(arg) <= 2)
	{
		printf("ERROR, map INCCORECT");
		return (false);
	}
	evry->balade.nb_line = ft_count_line(arg);
	fd = open(arg, O_RDONLY);
	evry->map = malloc(sizeof(char *) * (evry->balade.nb_line + 1));
	if (!evry->map)
		return (free(evry->map),evry->map = NULL, NULL);
	while (evry->balade.nb_line > draveil.i)
	{
		evry->map[draveil.i] = get_next_line(fd);
		draveil.i++;
	}
	evry->map[draveil.i] = NULL;
	return (close(fd),evry->map);
}

bool	check_len_char(char **map, t_all_the_time *evry)
{
	t_go lib;

	evry->balade.nb_colum = 0;
	lib.ycheh = 0;
	while(lib.ycheh < evry->balade.nb_line)
	{
		evry->balade.nb_colum = ft_strlensolong(map[lib.ycheh]);
		if (lib.ycheh > 0)
		{
			if (ft_strlensolong(map[lib.ycheh - 1]) != evry->balade.nb_colum)
			{	
				return (printf("ERROR, SIZE MAP"), false);
			}
		}
	lib.ycheh ++;
	}
	if (check_map_all_C(map,evry) == true)
	{
		return (printf("ALL CHAR\n"),true);
	}
	else
	{	
		return (printf("ERROR, WRONG CHAR\n"), false);
	}
}

bool	check_map_all_C(char **map, t_all_the_time *evry)
{
	t_go lib;
	(void) map;

	lib.ycheh = 0;
	while (evry->map[lib.ycheh] != NULL)
	{
		lib.x = 0;
		while(evry->map[lib.ycheh][lib.x] != '\0')
		{
			if (evry->map[lib.ycheh][lib.x] == 'E')
			{
				evry->pos_x_exit = lib.x;
				evry->pos_y_exit = lib.ycheh;
			}
			if (evry->map[lib.ycheh][lib.x] == 'C')
				evry->nb_collectible++ ;
			if (!(ft_strchrmap("10EPC\n", evry->map[lib.ycheh][lib.x])))
				return (false);
			lib.x ++;
		}
		lib.ycheh ++;
	}
	return (true);
}
