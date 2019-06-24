/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafond- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:48:08 by glafond-          #+#    #+#             */
/*   Updated: 2019/02/27 18:52:56 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

t_func		ft_bsq(t_data *data)
{
	if ((data->fd = open(data->path, O_RDONLY)) == OPEN_ERROR)
		return (ERROR);
	if (ft_start(data) == ERROR)
		return (ERROR);
	if (close(data->fd) == CLOSE_ERROR)
		return (ERROR);
	if (ft_print_soluce(data) == ERROR)
		return (ERROR);
	free(data->buffer);
	return (SUCCESS);
}
