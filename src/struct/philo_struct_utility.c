/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_struct_utility.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/08 17:12:44 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/20 14:16:03 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include "info_struct_utility.h"
#include "philo_struct_utility.h"
#include "philo_enum.h"

void	free_philo(t_philo *philo)
{
	t_philo	*temp;

	if (!philo)
		return ;
	while (philo != NULL)
	{
		temp = philo->next;
		if (philo->fork != NULL)
		{
			pthread_mutex_destroy(philo->fork);
			free(philo->fork);
		}
		free(philo);
		philo = temp;
	}
	philo = NULL;
}

static t_philo	*new_philo(int id, t_info *info)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = id;
	philo->last_time_eaten = 0;
	philo->amount_eaten = 0;
	philo->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!philo->fork)
	{
		free_philo(philo);
		return (NULL);
	}
	philo->info = info;
	philo->next = NULL;
	return (philo);
}

static t_philo	*philo_add_back(t_philo *start, t_philo *add)
{
	t_philo	*i;

	if (!start || !add)
	{
		free_philo(start);
		return (NULL);
	}
	i = start;
	while (i->next)
		i = i->next;
	i->next = add;
	return (start);
}

void	loop_philos(t_philo	*philos, int loop)
{
	t_philo	*last;

	if (loop == 1)
	{
		last = philos;
		while (last->next)
			last = last->next;
		last->next = philos;
	}
	else
	{
		last = philos;
		while (last->id < last->next->id)
			last = last->next;
		last->next = NULL;
	}
}

t_philo	*init_philos(t_info *info)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = NULL;
	if (!info || info->philos == 0)
		return (NULL);
	while (i < info->philos)
	{
		if (!philos)
		{
			philos = new_philo(i + 1, info);
			if (!philos)
				return (NULL);
		}
		else
		{
			if (!philo_add_back(philos, new_philo(i + 1, info)))
				return (NULL);
		}
		i++;
	}
	loop_philos(philos, 1);
	return (philos);
}
