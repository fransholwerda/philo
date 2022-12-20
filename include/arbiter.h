/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arbiter.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fholwerd <fholwerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/15 13:13:28 by fholwerd      #+#    #+#                 */
/*   Updated: 2022/12/20 14:11:36 by fholwerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARBITER_H
# define ARBITER_H

# include "info_struct_utility.h"
# include "philo_struct_utility.h"

int		philo_alive_check(t_philo *philo, t_info *info);
void	arbiter(t_philo *philo, t_info *info);

#endif
