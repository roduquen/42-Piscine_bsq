/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafond- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 22:39:11 by glafond-          #+#    #+#             */
/*   Updated: 2019/02/27 22:26:38 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

t_func		ft_read_stdin(t_data *data)
{
	char			*tmp_buffer;
	unsigned int	cur_l;

	cur_l = 1;
	if (!(tmp_buffer = (char*)malloc(sizeof(char) * (data->len + 1))))
		return (MALLOC_ERROR);
	while (cur_l < data->cs_nb_line
			&& read(data->fd, tmp_buffer, data->len + 1))
	{
		data->buffer = ft_strjoin(data, tmp_buffer, (data->len + 1) * cur_l);
		cur_l++;
	}
	if (cur_l != data->cs_nb_line || read(data->fd, tmp_buffer, data->len + 1))
		return (MAP_ERROR);
	free(tmp_buffer);
	return (SUCCESS);
}
