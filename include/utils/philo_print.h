/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_print.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/13 13:51:26 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/16 17:35:27 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_PRINT_H
# define PHILO_PRINT_H

# include "philo_struct_utility.h"

int		alive_check(t_info *info);
void	philo_print(t_philo *philo, char *msg);

#endif
