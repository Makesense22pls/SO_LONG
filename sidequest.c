/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sidequest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:34:20 by mafourni          #+#    #+#             */
/*   Updated: 2024/04/15 17:04:48 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

t_all_the_time	*ft_peter(void)
{
	t_all_the_time *peter;

	peter = malloc(sizeof(t_all_the_time));
	if(!peter)
		return(0);
	peter->map = NULL;
	return(peter);
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

// t_all_the_time	*ft_peter(void)
// {
// 	t_all_the_time *peter;
	
// 	peter = malloc(sizeof(t_all_the_time));
// 	if(!peter)
// 		return(0);
// 	peter->count = 0;
// 	peter->len = 0;
// 	peter->x = 0;
// 	peter->y = 0;
// 	return(peter);
// }
