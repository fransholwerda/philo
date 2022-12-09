/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/29 15:01:23 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/09 16:23:01 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "philosopher.h"

	// number_of_philos >= 1
	// time_to_die >= 0
	// time_to_eat >= 0
	// time_to_sleep >= 0
	// number_of_times_each_philo_must_eat >= 0
#include <stdio.h>
int	numeric_args(int argc, char *argv[])
{
	if (!ft_isnum(argv[1]) || !ft_isnum(argv[2]) || \
		!ft_isnum(argv[3]) || !ft_isnum(argv[4]))
	{
		write(2, "Use numeric values only.\n", 25);
		return (0);
	}
	if (argc == 6)
	{
		if (!ft_isnum(argv[5]))
		{
			write(2, "Use numeric values only.\n", 25);
			return (0);
		}
	}
	return (1);
}

void	check_for_leaks(void)
{
	system("leaks philo");
}

int	main(int argc, char *argv[])
{
	//atexit(check_for_leaks);
	if (argc < 5 || argc > 6)
	{
		write(2, "Use 4 or 5 arguments.\n", 22);
		return (EXIT_FAILURE);
	}
	if (!numeric_args(argc, argv))
		return (EXIT_FAILURE);
	if (!philosophers(argc, argv))
		return (EXIT_FAILURE);
	printf("exiting\n");
	return (EXIT_SUCCESS);
}
