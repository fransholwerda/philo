/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/29 15:01:23 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/20 15:11:19 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "philosopher.h"
#include <stdio.h>

int	numeric_args(int argc, char *argv[])
{
	if (!ft_isnum(argv[1]) || !ft_isnum(argv[2]) || \
		!ft_isnum(argv[3]) || !ft_isnum(argv[4]))
	{
		printf("Use numeric values only.\n");
		return (0);
	}
	if (argc == 6)
	{
		if (!ft_isnum(argv[5]))
		{
			printf("Use numeric values only.\n");
			return (0);
		}
	}
	return (1);
}

/* void	check_for_leaks(void)
{
	system("leaks philo");
	atexit(check_for_leaks);
} */

int	main(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
	{
		printf("Use 4 or 5 arguments.\n");
		return (EXIT_FAILURE);
	}
	if (!numeric_args(argc, argv))
		return (EXIT_FAILURE);
	if (!philosophers(argc, argv))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
