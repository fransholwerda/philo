/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isnum.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/29 17:26:00 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/02 14:38:19 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strlen.h"
#include "ft_isdigit.h"

int	ft_isnum(char *str)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
