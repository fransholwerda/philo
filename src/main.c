/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/29 15:01:23 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/11/29 17:53:05 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

	// number_of_philos >= 1
	// time_to_die >= 0
	// time_to_eat >= 0
	// time_to_sleep >= 0
	// number_of_times_each_philo_must_eat >= 0
void	numeric_args(int argc, char *argv)
{
	if (!ft_isnum(argv[1]) || !ft_isnum(argv[2]) || \
		!ft_isnum(argv[3]) || !ft_isnum(argv[4]))
		stop("Use numeric values only.\n");
	if (argc == 6)
	{
		if (!ft_isnum(argv[5]))
			stop("Use numeric values only.\n");
	}
}

int	main(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
		stop("Use 4 or 5 arguments.\n");
	numeric_args(argc, argv);
	return (0);
}
