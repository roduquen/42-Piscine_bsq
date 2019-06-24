/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:12:23 by roduquen          #+#    #+#             */
/*   Updated: 2019/02/27 23:08:49 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

t_func		ft_first_line(t_data *data)
{
	unsigned int i;

	if (!(read(data->fd, data->buffer, data->len + 1)))
		return (ERROR);
	i = 0;
	if (data->buffer[0] == '\n')
		return (MAP_ERROR);
	while (i < data->len)
	{
		if (data->buffer[i] != data->cs_obstacle
				&& data->buffer[i] != data->cs_empty)
			return (MAP_ERROR);
		i++;
	}
	return (SUCCESS);
}

t_func		ft_first_tab(t_data *data)
{
	unsigned int	i;

	if (!(data->tab1 = (unsigned int*)malloc(sizeof(unsigned int) * data->len)))
		return (MALLOC_ERROR);
	i = 0;
	data->sq_size = 0;
	data->sq_line = 0;
	data->sq_column = 0;
	while (i < data->len)
	{
		if (data->sq_size == 0 && data->buffer[i] == data->cs_empty)
		{
			data->tab1[i] = 1;
			data->sq_size = 1;
			data->sq_line = 1;
			data->sq_column = i + 1;
		}
		else if (data->buffer[i] == data->cs_empty)
			data->tab1[i] = 1;
		else
			data->tab1[i] = 0;
		i++;
	}
	return (SUCCESS);
}
