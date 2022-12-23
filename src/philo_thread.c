/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_thread.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/23 15:28:08 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/23 15:33:25 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "info_struct_utility.h"
#include "philo_struct_utility.h"
#include "my_time.h"
#include "philo_enum.h"
#include "philo_print.h"
#include "eat.h"

void	set_death(t_info *info)
{
	pthread_mutex_lock(info->death_lock);
	info->death = DEATH;
	pthread_mutex_unlock(info->death_lock);
}

static void	run_thread(t_philo *philo)
{
	int		eat_status;

	while (1)
	{
		if (philo->info->philos == 1)
		{
			philo_print(philo, "has taken a fork\n");
			return ;
		}
		if (alive_check(philo->info) == DEATH)
			return ;
		eat_status = eat(philo);
		if (eat_status == DONE_EATING || eat_status == FAIL)
			return ;
		philo_print(philo, "is sleeping\n");
		if (proper_sleep(philo->info->sleep_time) == FAIL)
		{
			philo_print(philo, "sleep went wrong\n");
			set_death(philo->info);
			return ;
		}
		philo_print(philo, "is thinking\n");
	}
}

void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	run_thread(philo);
	return (NULL);
}
