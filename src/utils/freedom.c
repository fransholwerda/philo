/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   freedom.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 13:31:31 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/09 14:22:56 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include "info_struct_utility.h"
#include "philo_struct_utility.h"

void	free_all(t_philo *philo, t_info *info, pthread_t *threads)
{
	if (info)
		free_info(info);
	if (philo)
		free_philo(philo);
	if (threads)
	{
		free(threads);
		threads = NULL;
	}
}
