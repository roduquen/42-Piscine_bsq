/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafond- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:52:13 by glafond-          #+#    #+#             */
/*   Updated: 2019/02/26 21:12:42 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

t_func			ft_atoi(t_data *data, char *start, char *end)
{
	unsigned int	nb_line;

	nb_line = 0;
	while (*start >= '0' && *start <= '9' && start < end)
	{
		nb_line = nb_line * 10 + (*start - '0');
		start++;
	}
	if (start < end)
		return (MAP_ERROR);
	data->cs_nb_line = nb_line;
	return (SUCCESS);
}

t_func			ft_load_charset(t_data *data, char *charset)
{
	data->cs_empty = *charset;
	charset++;
	data->cs_obstacle = *charset;
	if (data->cs_obstacle == data->cs_empty)
		return (MAP_ERROR);
	charset++;
	data->cs_full = *charset;
	if (data->cs_full == data->cs_empty || data->cs_full == data->cs_obstacle)
		return (MAP_ERROR);
	return (SUCCESS);
}

t_func			ft_charset(t_data *data)
{
	char			*charset;
	char			*cpy_charset;
	unsigned int	len;

	if (!(charset = (char*)malloc(sizeof(char) * 2)))
		return (MALLOC_ERROR);
	cpy_charset = charset;
	if (!read(data->fd, charset, 1))
		return (MAP_ERROR);
	while (*cpy_charset != '\n')
	{
		cpy_charset++;
		len = cpy_charset - charset;
		if (!(charset = ft_realloc(charset, len)))
			return (MALLOC_ERROR);
		cpy_charset = charset + len;
		if (!read(data->fd, cpy_charset, 1))
			return (MAP_ERROR);
	}
	if (ft_atoi(data, charset, cpy_charset - 3) == MAP_ERROR)
		return (MAP_ERROR);
	if (ft_load_charset(data, cpy_charset - 3) == MAP_ERROR)
		return (MAP_ERROR);
	free(charset);
	return (SUCCESS);
}
