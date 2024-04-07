/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 00:09:46 by mafourni          #+#    #+#             */
/*   Updated: 2024/04/07 19:11:39 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/ft_printf.h"

bool	check_nb_arg(int argc)
{
	if (argc != 2)
		{
			ft_printf("WRONG NUMBERS OF ARGS");
			return (false);
		}
	return (true);
}	

bool	check_ber(char *str)
{
	int i;

	i = 0;
	while (str[i])
			i++;
	i--;
	if (str[i] == 'r' && str[i-1] == 'e' && str[i-2] == 'b' && str[i-3] == '.')
		{
		ft_printf("SUCCESS ! for godd name of last arg\n");
		return (true);
		}
	else
		ft_printf("ERROR! INVALID MAP NAME !");
		return (false);
}

// int main(int argc, char **argv)
// {
// 	if (!(check_nb_arg(argc)))
// 		return(0);
// 	if (!(check_ber(argv[1])))
// 		return (0);
	
// 	return (1);
// }