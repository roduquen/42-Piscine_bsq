/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solveur_bsq.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:39:16 by roduquen          #+#    #+#             */
/*   Updated: 2019/02/27 19:13:59 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>

t_func		ft_resolv_bsq(t_data *data)
{
	unsigned int	cur_l;
	unsigned int	cur_c;

	cur_l = 1;
	while (read(data->fd, data->buffer, data->len + 1))
	{
		cur_c = 0;
		while (cur_c < data->len && data->buffer[cur_c])
		{
			if (data->buffer[cur_c] == data->cs_empty)
				ft_load_result(data, cur_c++, cur_l);
			else if (data->buffer[cur_c] == data->cs_obstacle)
				data->tab2[cur_c++] = 0;
			else
				return (MAP_ERROR);
		}
		if (data->buffer[cur_c] != '\n')
			return (MAP_ERROR);
		cur_l++;
		ft_swap(data);
	}
	if (data->cs_nb_line != cur_l)
		return (MAP_ERROR);
	return (SUCCESS);
}
