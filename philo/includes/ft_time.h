/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:54:36 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/24 21:54:26 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TIME_H
# define FT_TIME_H

# include <unistd.h>
# include <sys/time.h>

long long	get_milisecond(long long start_time);
void		msleep(long long time);

#endif // FT_TIME_H
