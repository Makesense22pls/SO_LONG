/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:37:10 by mafourni          #+#    #+#             */
/*   Updated: 2024/04/07 19:43:46 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*ft_strchrmap(const char *s, int c)
{
	unsigned char	c_;
	unsigned char	*s_;

	c_ = (unsigned char) c;
	s_ = (unsigned char *) s;
	if (s == NULL)
		return (NULL);
	if (c_ == '\0')
	{
		while (*s_ != '\0')
			s_++;
		return (1);
	}
	while (*s_ != '\0')
	{
		if (*s_ == c_)
			return (1);
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
	str = get_next_line(fd);
	while (str != NULL)
		{	
			free(str);
			str = get_next_line(fd);
			i++;
		}
	return (close(fd),i);
}

char **full_map(char *arg)
{
	int i;
	int x;
	char **map;
	int fd;
	int count_line;
	
	i = 0;
	x = 1;
	count_line = ft_count_line(arg);
	fd = open(arg, O_RDONLY);
	map = malloc(sizeof(char *) * (count_line + 1));
	if (!map)
		return (free(map), map = NULL, NULL);
	while (i < count_line)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[count_line] = NULL;
	return (close(fd),map);
}
bool	check_map_all_C(char *arg, char **map)
{
	int x;
	int y;
	int limit;
	
	x = 0;
	y = 0;
	limit = ft_count_line(arg);
	
	while (y < limit && map[limit][x] != '\0')
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (ft_strchrmap(map[y][x], '1'))
			{
				printf("1 FOUND");
			}
			if (ft_strchrmap(map[y][x], '0'))
			{
				printf("1 FOUND");
			}
			if (ft_strchrmap(map[y][x], 'E'))
			{
				printf("1 FOUND");
			}
			if (ft_strchrmap(map[y][x], 'P'))
			{
				printf("1 FOUND");
			}
			if (ft_strchrmap(map[y][x], 'C'))
			{
				printf("1 FOUND");
			}
			x ++;
		}
		y ++;
	}
	return (1);
}

void	ft_free_all(char **map)
{
	int i;

	i = 0;
	while(map[i])
	{
		free(map[i]);
		map[i] = 0;
		i++;
	}
	free(map);
	map = NULL;
}
