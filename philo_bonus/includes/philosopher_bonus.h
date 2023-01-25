/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:55:12 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/25 01:53:48 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_BONUS_H
# define PHILOSOPHER_BONUS_H

# include "config_bonus.h"
# include "ft_time_bonus.h"
# include "print_bonus.h"

# include <pthread.h>

void	philosopher(t_philosopher *philo);

#endif // PHILOSOPHER_BONUS_H