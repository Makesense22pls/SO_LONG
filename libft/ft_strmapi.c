/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:14:49 by mafourni          #+#    #+#             */
/*   Updated: 2024/03/04 14:33:17 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*copie;
	int		i;

	i = 0;
	len = strlen(s);
	copie = malloc(sizeof(char) * (len + 1));
	if (!copie)
		return (NULL);
	while (s[i])
	{
		copie[i] = f(i, s[i]);
		i++;
	}
	copie[i] = '\0';
	return (copie);
}

char salut(unsigned int go, char c)
{
	(void) go;
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
