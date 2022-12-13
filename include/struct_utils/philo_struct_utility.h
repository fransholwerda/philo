/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_struct_utility.h                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 12:52:22 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/13 15:41:18 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_UTILITY_H
# define PHILO_STRUCT_UTILITY_H

# include <pthread.h>
# include "info_struct_utility.h"

typedef struct s_philo
{
	int				id;
	long int		last_time_eaten;
	long int		last_time_slept;
	int				death;
	int				amount_eaten;
	pthread_mutex_t	*fork;
	t_info			*info;
	struct s_philo	*next;
}		t_philo;

void	free_philo(t_philo *philo);
t_philo	*init_philos(t_info *info);

#endif
