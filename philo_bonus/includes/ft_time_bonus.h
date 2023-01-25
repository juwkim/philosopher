/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:51:06 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/24 22:51:19 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TIME_BONUS_H
# define FT_TIME_BONUS_H

# include <unistd.h>
# include <sys/time.h>

long long	get_milisecond(long long start_time);
void		msleep(long long time);

#endif // FT_TIME_BONUS_H
