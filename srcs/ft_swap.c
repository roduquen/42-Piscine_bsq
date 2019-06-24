/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:05:10 by roduquen          #+#    #+#             */
/*   Updated: 2019/02/27 11:07:55 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_func		ft_swap(t_data *data)
{
	unsigned int	*tmp;

	tmp = data->tab1;
	data->tab1 = data->tab2;
	data->tab2 = tmp;
	return (SUCCESS);
}
