/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:55:49 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/25 01:03:28 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATE_BONUS_H
# define SIMULATE_BONUS_H

# include <fcntl.h>
# include <signal.h>

# include "config_bonus.h"
# include "philosopher_bonus.h"

void	simulate(t_manager *manager);

#endif // SIMULATE_BONUS_H
