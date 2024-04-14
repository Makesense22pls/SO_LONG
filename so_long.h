/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:14:18 by mafourni          #+#    #+#             */
/*   Updated: 2024/04/14 16:45:33 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include "MLX42.h"

typedef struct s_go
{
	size_t i;
	size_t x;
	size_t y;
	size_t count;
	size_t len;
	size_t count_line;
}t_go;

typedef struct s_all_the_time
{
	t_go	balade;
}t_all_the_time;


t_all_the_time	*ft_peter(void);
bool	check_ber(char *str);
bool	check_nb_arg(int argc);
int		ft_count_line(char *arg);
char **full_map(char *arg, t_all_the_time *evry);
void	ft_free_all(char **map);
bool	check_map_all_C(char **map);
char	*ft_strchrmap(const char *s, int c);
bool	check_len_char(char **map, t_all_the_time *evry);
size_t	ft_strlensolong(const char *s);

