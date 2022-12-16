/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eat.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/13 12:33:45 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/16 16:36:06 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "info_struct_utility.h"
#include "philo_struct_utility.h"
#include "philo_enum.h"
#include "philo_print.h"
#include "my_time.h"

static void	grab_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->fork);
	philo_print(philo, "has taken a fork\n");
	pthread_mutex_lock(philo->next->fork);
	philo_print(philo, "has taken a fork\n");
}

static void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->next->fork);
}

int	eat(t_philo *philo)
{
	grab_forks(philo);
	philo_print(philo, "is eating\n");
	proper_sleep(philo->info->eat_time);
	philo->last_time_eaten = timestamp(philo->info->start_time);
	philo->amount_eaten++;
	drop_forks(philo);
	if (philo->amount_eaten >= philo->info->eat_amount)
		return (DONE_EATING);
	else
		return (SUCCESS);
	// Do a thing for amount of times eaten
}
