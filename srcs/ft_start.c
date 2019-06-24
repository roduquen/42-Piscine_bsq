/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:52:01 by roduquen          #+#    #+#             */
/*   Updated: 2019/02/27 19:15:38 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

t_func		ft_init(t_data *data)
{
	data->len = 0;
	data->sq_line = 0;
	data->sq_column = 0;
	data->sq_size = 0;
	data->buffer = NULL;
	data->tab1 = NULL;
	data->tab2 = NULL;
	data->cs_nb_line = 0;
	data->cs_obstacle = 0;
	data->cs_empty = 0;
	data->cs_full = 0;
	return (SUCCESS);
}

t_func		ft_start(t_data *data)
{
	if (ft_init(data) != SUCCESS)
		return (ERROR);
	if (ft_charset(data) == ERROR)
		return (ERROR);
	if (ft_count(data) == ERROR)
		return (ERROR);
	if (!(data->buffer = (char*)malloc(sizeof(char) * data->len + 1)))
		return (MALLOC_ERROR);
	if (ft_first_line(data) == MAP_ERROR)
		return (ft_free_buffer(data));
	if (ft_first_tab(data) == MALLOC_ERROR)
		return (ft_free_buffer(data));
	if (!(data->tab2 = (unsigned int*)malloc(sizeof(unsigned int) * data->len)))
		return (ft_free_buffer(ft_free_tab1(data)));
	if (ft_resolv_bsq(data) == MAP_ERROR)
		return (ft_free_buffer(ft_free_tab1(ft_free_tab2(data))));
	free(data->tab1);
	free(data->tab2);
	return (SUCCESS);
}

t_data		*ft_free_tab1(t_data *data)
{
	free(data->tab1);
	return (data);
}

t_data		*ft_free_tab2(t_data *data)
{
	free(data->tab2);
	return (data);
}

t_func		ft_free_buffer(t_data *data)
{
	free(data->buffer);
	return (ERROR);
}
