/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafond- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 00:36:40 by glafond-          #+#    #+#             */
/*   Updated: 2019/02/27 01:06:51 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "bsq.h"

t_func		ft_count(t_data *data)
{
	char			c;
	unsigned int	counter;
	int				fd;

	counter = 0;
	if ((fd = open(data->path, O_RDONLY)) == OPEN_ERROR)
		return (OPEN_ERROR);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
	}
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		counter++;
	}
	data->len = counter;
	if (close(fd) == CLOSE_ERROR)
		return (CLOSE_ERROR);
	return (SUCCESS);
}
