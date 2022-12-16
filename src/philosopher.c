/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 12:34:58 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/16 17:36:26 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "info_struct_utility.h"
#include "philo_struct_utility.h"
#include "arbiter.h"
#include "freedom.h"
#include "utils.h"
#include "my_time.h"
#include "eat.h"
#include "philo_print.h"
#include "threads.h"
#include "philo_enum.h"

void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (alive_check(philo->info) == DEATH)
			return (NULL);
		eat(philo);
		philo_print(philo, "is sleeping\n");
		proper_sleep(philo->info->sleep_time);
		philo_print(philo, "is thinking\n");
	}
	return (NULL);
}

int	init_mutex(t_philo *philo)
{
	t_philo	*temp;
	int		i;

	temp = philo;
	i = 0;
	while (i < philo->info->philos)
	{
		if (pthread_mutex_init(temp->fork, NULL) != 0)
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}

int	engage_philos(t_philo *philo, t_info *info, pthread_t *threads)
{
	int			i;
	int			error;

	if (pthread_mutex_init(info->print, NULL) != 0)
		return (0);
	i = 0;
	if (init_mutex(philo) == 0)
		return (0);
	while (i < info->philos)
	{
		error = pthread_create(&threads[i], NULL, &philo_thread, (void *)philo);
		if (error != 0)
			return (0);
		philo = philo->next;
		i++;
	}
	return (1);
}

int	philosophers(int argc, char *argv[])
{
	t_info		*info;
	t_philo		*philo;
	pthread_t	*threads;

	info = init_info(argc, argv);
	philo = init_philos(info);
	threads = create_threads(info);
	if (!info || !philo || !threads)
	{
		free_all(philo, info, threads);
		return (0);
	}
	if (engage_philos(philo, info, threads) == 0)
	{
		free_all(philo, info, threads);
		return (0);
	}
	arbiter(philo, info); //USE THE RETURN VALUE
	join_threads(threads, info->philos);
	loop_philos(philo, 0);
	free_all(philo, info, threads);
	return (1);
}
