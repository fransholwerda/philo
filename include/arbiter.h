/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arbiter.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/15 13:13:28 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/16 13:24:07 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARBITER_H
# define ARBITER_H

# include "info_struct_utility.h"
# include "philo_struct_utility.h"

int	philo_alive_check(t_philo *philo, t_info *info);
int	arbiter(t_philo *philo, t_info *info);

#endif
