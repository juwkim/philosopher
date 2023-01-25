/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:54:58 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/25 03:14:15 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_BONUS_H
# define CONFIG_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <semaphore.h>

# define MAX_PHILO_COUNT 200

typedef struct s_manager
{
	int			philo_count;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat;
	bool		is_died;
	long long	start_time;
	pid_t		pids[MAX_PHILO_COUNT];
	int			eat_count[MAX_PHILO_COUNT];
	long long	last_eat_time[MAX_PHILO_COUNT];
	sem_t		*sm_eat[MAX_PHILO_COUNT];
	sem_t		*sm_dead;
	sem_t		*sm_done;
	sem_t		*sm_start;
	sem_t		*sm_print;
	sem_t		*sm_fork;
}	t_manager;

typedef struct s_philosopher
{
	int				id;
	t_manager		*manager;
}	t_philosopher;

#endif // CONFIG_BONUS_H
