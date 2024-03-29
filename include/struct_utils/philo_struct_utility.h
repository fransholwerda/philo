/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_struct_utility.h                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 12:52:22 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/20 13:08:10 by fholwerd      ########   odam.nl         */
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
	int				amount_eaten;
	pthread_mutex_t	*fork;
	t_info			*info;
	struct s_philo	*next;
}		t_philo;

void	free_philo(t_philo *philo);
void	loop_philos(t_philo	*philos, int loop);
t_philo	*init_philos(t_info *info);

#endif
