/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 00:09:46 by mafourni          #+#    #+#             */
/*   Updated: 2024/04/07 01:28:34 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/ft_printf.h"

bool	check_ber(char *str)
{
	int i;

	i = 0;
	bool x = true;
	while (str[i])
			i++;
	i--;
	if (str[i] == 'r' && str[i-1] == 'e' && str[i-2] == 'b' && str[i-3] == '.')
		{
		ft_printf("SUCCESS !");
		return (x);
		}
	else
		ft_printf("ERROR! INVALID MAP NAME !");
		return (false);
}
bool	check_nb_arg(int argc)
{
	bool x = true;
	if (argc != 2)
		{
			ft_printf("WRONG NUMBERS OF ARGS");
			return (0);
		}
	return (x);
}	

int main(int argc, char **argv)
{
	if (!(check_nb_arg(argc)));
		return(0);
	if (!(check_ber(argv[1])));
		return (0);
	return (1);
}