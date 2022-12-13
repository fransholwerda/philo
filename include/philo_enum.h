/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_enum.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/13 12:43:47 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/13 16:08:20 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ENUM_H
# define PHILO_ENUM_H

typedef enum e_status
{
	SUCCESS,
	FAIL,
	DEATH,
	ALIVE,
	DONE_EATING,
}	t_status;

#endif
