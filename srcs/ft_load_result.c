/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:07:11 by roduquen          #+#    #+#             */
/*   Updated: 2019/02/27 13:56:15 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_func		ft_load_result(t_data *data, unsigned int column, unsigned int line)
{
	if (column > 0)
		data->tab2[column] = ft_min(data, column);
	else
		data->tab2[column] = 1;
	if (data->tab2[column] > data->sq_size)
	{
		data->sq_size = data->tab2[column];
		data->sq_line = line + 1;
		data->sq_column = column + 1;
	}
	return (SUCCESS);
}
