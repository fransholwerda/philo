/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_struct.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/08 17:12:44 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/08 17:18:31 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philosopher.h"

void	free_philo(t_philo *philo)
{
	t_philo	*temp;

	while (philo)
	{
		temp = philo;
		philo = philo->next;
		free(temp);
		temp = NULL;
	}
	philo = NULL;
}

t_philo	*new_philo(int id, t_info *info)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = id;
	philo->last_time_eaten = 0;
	philo->last_time_slept = 0;
	philo->death = 0;
	philo->amount_eaten = 0;
	philo->info = info;
	philo->next = NULL;
}

t_philo	*philo_add_back(t_philo *start, t_philo *add)
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

t_philo	*init_philos(int amount, t_info *info)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = NULL;
	while (i < amount)
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
}
