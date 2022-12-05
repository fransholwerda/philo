/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/29 17:49:36 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/02 16:27:03 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

typedef struct s_philo
{
	int	last_time_eaten;

}		t_philo;

typedef struct s_info
{
	int			philos;
	int			die_time;
	int			eat_time;
	int			sleep_time;
	int			eat_amount;
	long int	start_time;
}				t_info;

int	philosophers(int argc, char *argv[]);

#endif
