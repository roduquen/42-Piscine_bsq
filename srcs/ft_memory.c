/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:00:24 by roduquen          #+#    #+#             */
/*   Updated: 2019/02/26 19:58:36 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

char	*ft_realloc(char *str, unsigned int size)
{
	char	*new_str;
	char	*cpy_new_str;
	char	*cpy_str;

	if (!(new_str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	cpy_new_str = new_str;
	cpy_str = str;
	while (cpy_str - str < size)
		*cpy_new_str++ = *cpy_str++;
	*cpy_new_str = 0;
	free(str);
	return (new_str);
}
