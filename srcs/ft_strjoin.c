/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafond- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:09:17 by glafond-          #+#    #+#             */
/*   Updated: 2019/02/27 18:35:55 by glafond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

char		*ft_strjoin(t_data *data, char *str, unsigned int size)
{
	char			*new_buffer;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!(new_buffer = (char*)malloc(sizeof(char) * (size + data->len + 1))))
		return (NULL);
	while (i < size)
	{
		new_buffer[i] = data->buffer[i];
		i++;
	}
	j = 0;
	while (i < size + data->len + 1)
		new_buffer[i++] = str[j++];
	free(data->buffer);
	return (new_buffer);
}
