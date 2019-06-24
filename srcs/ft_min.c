/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafond- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:53:24 by glafond-          #+#    #+#             */
/*   Updated: 2019/02/26 18:47:29 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

unsigned int	ft_min(t_data *data, unsigned int column)
{
	if (data->tab1[column - 1] <= data->tab1[column]
			&& data->tab1[column - 1] <= data->tab2[column - 1])
		return (data->tab1[column - 1] + 1);
	if (data->tab1[column] <= data->tab1[column - 1]
			&& data->tab1[column] <= data->tab2[column - 1])
		return (data->tab1[column] + 1);
	if (data->tab2[column - 1] <= data->tab1[column - 1]
			&& data->tab2[column - 1] <= data->tab1[column])
		return (data->tab2[column - 1] + 1);
	return (ERROR);
}
