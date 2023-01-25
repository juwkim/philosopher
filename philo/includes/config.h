/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:43:31 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/24 21:56:11 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>

# define MAX_PHILO_COUNT 200

typedef struct s_manager
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	long long		start_time;
	int				eat_count[MAX_PHILO_COUNT];
	long long		last_eat_time[MAX_PHILO_COUNT];
	pthread_mutex_t	m_eat[MAX_PHILO_COUNT];
	pthread_mutex_t	m_forks[MAX_PHILO_COUNT];
	pthread_mutex_t	m_print;
}	t_manager;

typedef struct s_philosopher
{
	int				id;
	t_manager		*manager;
	pthread_t		thread;
}	t_philosopher;

#endif // CONFIG_H
