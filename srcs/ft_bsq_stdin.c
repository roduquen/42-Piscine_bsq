/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq_stdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 09:20:01 by roduquen          #+#    #+#             */
/*   Updated: 2019/02/27 23:10:38 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

t_func		ft_stdin_init(t_data *data)
{
	if (ft_init(data) != SUCCESS)
		return (ERROR);
	data->fd = 0;
	if (ft_charset(data) != SUCCESS)
		return (ERROR);
	if (!(data->buffer = (char*)malloc(sizeof(char) * data->cs_nb_line + 1)))
		return (MALLOC_ERROR);
	if (ft_first_line_stdin(data) != SUCCESS)
		return (ft_free_buffer(data));
	if (ft_read_stdin(data) != SUCCESS)
		return (ft_free_buffer(data));
	if (ft_first_tab(data) != SUCCESS)
		return (ft_free_buffer(data));
	if (!(data->tab2 = (unsigned int*)malloc(sizeof(unsigned int) * data->len)))
		return (ft_free_buffer(ft_free_tab1(data)));
	if (ft_resolv_bsq_stdin(data) != SUCCESS)
		return (ft_free_buffer(ft_free_tab1(ft_free_tab2(data))));
	free(data->tab1);
	free(data->tab2);
	if (ft_print_stdin(data) != SUCCESS)
		return (ft_free_buffer(data));
	free(data->buffer);
	return (SUCCESS);
}

t_func		ft_first_line_stdin(t_data *data)
{
	unsigned int	i;
	unsigned int	ret;

	i = 0;
	while ((ret = read(data->fd, data->buffer + i, 1)))
	{
		if (data->buffer[i] == '\n' && i != 0)
			break ;
		if (data->buffer[i] != data->cs_obstacle
				&& data->buffer[i] != data->cs_empty)
			return (MAP_ERROR);
		i++;
		if (i % data->cs_nb_line == 0)
		{
			data->buffer[i] = 0;
			if (!(data->buffer = ft_realloc_stdin(data->buffer, i
							+ data->cs_nb_line + 1)))
				return (MALLOC_ERROR);
		}
	}
	if (!ret)
		return (MAP_ERROR);
	data->len = i;
	data->buffer[i + 1] = 0;
	return (SUCCESS);
}

char		*ft_realloc_stdin(char *str, unsigned int size)
{
	char	*new_str;
	char	*cpy_new_str;
	char	*cpy_str;

	if (!(new_str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	cpy_new_str = new_str;
	cpy_str = str;
	while (*cpy_str)
		*cpy_new_str++ = *cpy_str++;
	*cpy_new_str = 0;
	free(str);
	return (new_str);
}

t_func		ft_resolv_bsq_stdin(t_data *data)
{
	unsigned int	cur_l;
	unsigned int	cur_c;

	cur_l = 1;
	while (cur_l < data->cs_nb_line)
	{
		cur_c = 0;
		while (cur_c < data->len)
		{
			if (data->buffer[cur_c + (data->len + 1) * cur_l] == data->cs_empty)
				ft_load_result(data, cur_c++, cur_l);
			else if (data->buffer[cur_c + (data->len + 1) * cur_l]
					== data->cs_obstacle)
				data->tab2[cur_c++] = 0;
			else
				return (MAP_ERROR);
		}
		if (data->buffer[cur_c + (data->len + 1) * cur_l] != '\n')
			return (MAP_ERROR);
		cur_l++;
		if (ft_swap(data) != SUCCESS)
			return (ERROR);
	}
	return (SUCCESS);
}
