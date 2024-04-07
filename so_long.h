/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:14:18 by mafourni          #+#    #+#             */
/*   Updated: 2024/04/07 19:42:25 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include "MLX42.h"

bool	check_ber(char *str);
bool	check_nb_arg(int argc);
int		ft_count_line(char *arg);
char 	**full_map(char *arg);
void	ft_free_all(char **map);
bool	check_map_all_C(char *arg, char **map);
int	*ft_strchrmap(const char *s, int c);