/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_time.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 14:51:58 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/20 15:04:39 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include "arbiter.h"
#include "info_struct_utility.h"
#include "philo_struct_utility.h"
#include "philo_enum.h"

long int	get_start_time(void)
{
	struct timeval	current_time;
	long int		start_time;

	if (gettimeofday(&current_time, NULL) == -1)
		return (-1);
	start_time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (start_time);
}

long int	timestamp(long int start_time)
{
	struct timeval	current_time;
	long int		timestamp;

	if (gettimeofday(&current_time, NULL) == -1)
		return (-1);
	timestamp = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	timestamp -= start_time;
	return (timestamp);
}

int	proper_sleep(long int sleep_time, t_philo *philo)
{
	long int	start;
	long int	current;

	philo = NULL;
	start = get_start_time();
	current = timestamp(start);
	if (start == -1 || current == -1)
		return (FAIL);
	while (current <= sleep_time)
	{
		usleep(200);
		current = timestamp(start);
		if (current == -1)
			return (FAIL);
	}
	return (SUCCESS);
}
