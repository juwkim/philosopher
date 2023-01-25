/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:04:38 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/24 21:50:45 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "config.h"
# include "ft_time.h"

# define PICKUP		"has taken a fork"
# define EAT		"is eating"
# define SLEEP		"is sleeping"
# define THINK		"is thinking"
# define DIE		"died"

# define DEF_COLOR	"\033[1;39m"
# define GRAY		"\033[1;90m"
# define RED		"\033[1;91m"
# define GREEN		"\033[1;92m"
# define YELLOW		"\033[1;93m"
# define BLUE		"\033[1;94m"
# define MAGENTA	"\033[1;95m"
# define CYAN		"\033[1;96m"
# define WHITE		"\033[1;97m"

void	print_state(pthread_mutex_t *m_print, long long start_time, \
						int philo_id, const char *message);
void	print_died(pthread_mutex_t *m_print, long long start_time, \
						int philo_id, const char *message);
void	print_done(pthread_mutex_t *m_print);

#endif // PRINT_H
