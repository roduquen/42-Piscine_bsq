/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:18:23 by roduquen          #+#    #+#             */
/*   Updated: 2019/06/24 01:10:27 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	t_data			*data;
	unsigned int	i;

	i = 1;
	if (!(data = (t_data*)malloc(sizeof(t_data))))
		return (MALLOC_ERROR);
	if (ac == 1)
	{
		if (ft_stdin_init(data) != SUCCESS)
			write(2, "map error\n", 10);
	}
	else
	{
		while (av[i])
		{
			data->path = av[i];
			if (open(av[i], O_DIRECTORY) >= 0 || ft_bsq(data) == ERROR)
				write(2, "map error\n", 10);
			i++;
			if (av[i])
				write(1, "\n", 1);
		}
	}
	free(data);
	return (SUCCESS);
}
