/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/29 17:49:36 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/11/29 17:52:35 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

typedef struct s_philo
{
	int	philos;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	eat_amount;
}		t_philo;

#endif
