/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/29 17:49:36 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/08 17:23:48 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				last_time_eaten;
	int				last_time_slept;
	int				death;
	int				amount_eaten;
	pthread_mutex_t	*fork;
	t_info			*info;
	struct s_philo	*next;
}		t_philo;

typedef struct s_info
{
	int				philos;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_amount;
	long int		start_time;
	pthread_mutex_t	*print;
	pthread_mutex_t	*death;
}				t_info;

int	philosophers(int argc, char *argv[]);

#endif
