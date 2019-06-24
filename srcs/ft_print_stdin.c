/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stdin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafond- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:20:48 by glafond-          #+#    #+#             */
/*   Updated: 2019/02/27 23:06:16 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>

t_func		ft_print_stdin(t_data *data)
{
	unsigned int	cur_l;
	unsigned int	cur_c;

	cur_l = data->sq_line - data->sq_size;
	while (cur_l < data->sq_line)
	{
		cur_c = data->sq_column - data->sq_size;
		while (cur_c < data->sq_column)
		{
			data->buffer[cur_l * (data->len + 1) + cur_c] = data->cs_full;
			cur_c++;
		}
		cur_l++;
	}
	if (data->buffer[0] == '\n')
		return (ERROR);
	write(1, data->buffer, (data->len + 1) * data->cs_nb_line);
	return (SUCCESS);
}
