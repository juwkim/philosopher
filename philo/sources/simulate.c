/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:58:54 by seojo             #+#    #+#             */
/*   Updated: 2023/01/25 01:14:29 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulate.h"

static void	manage(t_manager *manager);
static bool	check_died(t_manager *manager, int philo_id);
static bool	check_done(t_manager *manager);

void	simulate(t_manager *manager)
{
	int				idx;
	t_philosopher	philos[MAX_PHILO_COUNT];

	idx = 0;
	while (idx < manager->philo_count)
	{
		pthread_mutex_init(&manager->m_eat[idx], NULL);
		pthread_mutex_init(&manager->m_forks[idx], NULL);
		philos[idx].id = idx;
		philos[idx].manager = manager;
		if (pthread_create(&philos[idx].thread, NULL, \
				philosopher, (void *)(philos + idx)) != 0)
			break ;
		++idx;
	}
	pthread_mutex_init(&manager->m_print, NULL);
	if (idx == manager->philo_count)
		manage(manager);
	pthread_mutex_destroy(&manager->m_print);
	while (--idx >= 0)
	{
		pthread_mutex_destroy(&manager->m_eat[idx]);
		pthread_mutex_destroy(&manager->m_forks[idx]);
	}
}

static void	manage(t_manager *manager)
{
	int	idx;
	int	is_dead;

	manager->start_time = get_milisecond(0);
	is_dead = false;
	while (true)
	{
		idx = -1;
		while (is_dead == false && ++idx < manager->philo_count)
			is_dead = check_died(manager, idx);
		if (is_dead)
		{
			print_died(&manager->m_print, manager->start_time, idx, DIE);
			break ;
		}
		if (manager->must_eat && check_done(manager))
		{
			print_done(&manager->m_print);
			break ;
		}
	}
}

static bool	check_died(t_manager *manager, int philo_id)
{
	long long	time_interval;

	pthread_mutex_lock(&manager->m_eat[philo_id]);
	if (manager->eat_count[philo_id] == 0)
		time_interval = get_milisecond(manager->start_time);
	else
		time_interval = get_milisecond(manager->last_eat_time[philo_id]);
	pthread_mutex_unlock(&manager->m_eat[philo_id]);
	if (time_interval > manager->time_to_die)
		return (true);
	return (false);
}

static bool	check_done(t_manager *manager)
{
	int	philo_id;

	philo_id = 0;
	while (philo_id < manager->philo_count)
	{
		pthread_mutex_lock(&manager->m_eat[philo_id]);
		if (manager->eat_count[philo_id] < manager->must_eat)
		{
			pthread_mutex_unlock(&manager->m_eat[philo_id]);
			return (false);
		}
		pthread_mutex_unlock(&manager->m_eat[philo_id]);
		++philo_id;
	}
	return (true);
}
