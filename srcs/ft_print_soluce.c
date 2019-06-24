/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_soluce.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafond- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:15:03 by glafond-          #+#    #+#             */
/*   Updated: 2019/02/27 23:07:51 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "bsq.h"

t_func		ft_set_square(t_data *data)
{
	unsigned int	sq_c;

	sq_c = 0;
	while (sq_c < data->sq_size)
	{
		data->buffer[data->sq_column - data->sq_size + sq_c] = data->cs_full;
		sq_c++;
	}
	return (SUCCESS);
}

t_func		ft_print_soluce(t_data *data)
{
	unsigned int	cur_l;

	cur_l = 0;
	if ((data->fd = open(data->path, O_RDONLY)) == OPEN_ERROR)
		return (OPEN_ERROR);
	while (data->buffer[0] != '\n')
		read(data->fd, data->buffer, 1);
	while (cur_l < data->sq_line - data->sq_size)
	{
		read(data->fd, data->buffer, data->len + 1);
		write(1, data->buffer, data->len + 1);
		cur_l++;
	}
	while (cur_l < data->sq_line)
	{
		read(data->fd, data->buffer, data->len + 1);
		ft_set_square(data);
		write(1, data->buffer, data->len + 1);
		cur_l++;
	}
	while (read(data->fd, data->buffer, data->len + 1))
		write(1, data->buffer, data->len + 1);
	if (close(data->fd) == CLOSE_ERROR)
		return (CLOSE_ERROR);
	return (SUCCESS);
}
