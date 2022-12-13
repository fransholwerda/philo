/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eat.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/13 12:33:45 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/13 15:26:19 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "info_struct_utility.h"
#include "philo_struct_utility.h"
#include "philo_enum.h"
#include "philo_print.h"

static void	grab_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->fork);
	philo_print(philo, "has grabbed a fork\n");
	pthread_mutex_lock(philo->next->fork);
	philo_print(philo, "has grabbed a fork\n");
}

static void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork);
	philo_print(philo, "has dropped a fork\n");
	pthread_mutex_unlock(philo->next->fork);
	philo_print(philo, "has dropped a fork\n");
}

int	eat(t_philo *philo)
{
	int	error;

	grab_forks(philo);
	philo_print(philo, "is eating\n");
	proper_sleep(philo->info->eat_time);
	philo->last_time_eaten = timestamp(philo->info->start_time);
	philo->amount_eaten++;
	drop_forks(philo);
	if (philo->amount_eaten >= philo->info->eat_amount)
		return (DONE_EATING);
	// Do a thing
}
