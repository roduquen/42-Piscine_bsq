/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 20:57:06 by roduquen          #+#    #+#             */
/*   Updated: 2019/02/27 18:31:35 by glafond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define MALLOC_ERROR -1
# define MAP_ERROR -1
# define OPEN_ERROR -1
# define CLOSE_ERROR -1
# define ERROR -1
# define SUCCESS 0

typedef struct			s_data
{
	unsigned int	len;
	unsigned int	sq_line;
	unsigned int	sq_column;
	unsigned int	sq_size;
	char			*buffer;
	unsigned int	*tab1;
	unsigned int	*tab2;
	int				fd;
	char			*path;
	unsigned int	cs_nb_line;
	char			cs_obstacle;
	char			cs_empty;
	char			cs_full;
}						t_data;

typedef int				t_func;

unsigned int			ft_min(t_data *data, unsigned int column);
t_func					ft_first_line(t_data *data);
t_func					ft_load_result(t_data *data, unsigned int column,
						unsigned int line);
t_func					ft_load_result_stdin(t_data *data, unsigned int column,
						unsigned int line);
t_func					ft_first_tab(t_data *data);
t_func					ft_resolv_bsq(t_data *data);
char					*ft_realloc(char *str, unsigned int size);
char					*ft_realloc_stdin(char *str, unsigned int size);
char					*ft_strjoin(t_data *data, char *str, unsigned int size);
t_func					ft_atoi(t_data *data, char *start, char *end);
t_func					ft_bsq(t_data *data);
t_func					ft_charset(t_data *data);
t_func					ft_load_charset(t_data *data, char *charset);
t_func					ft_print_soluce(t_data *data);
t_func					ft_print_stdin(t_data *data);
t_func					ft_set_square(t_data *data);
t_func					ft_init(t_data *data);
t_func					ft_start(t_data *data);
t_func					ft_count(t_data *data);
t_func					ft_stdin_init(t_data *data);
t_func					ft_first_line_stdin(t_data *data);
t_func					ft_read_stdin(t_data *data);
t_func					ft_resolv_bsq_stdin(t_data *data);
t_func					ft_swap(t_data *data);
t_func					ft_free_buffer(t_data *data);
t_data					*ft_free_tab1(t_data *data);
t_data					*ft_free_tab2(t_data *data);

#endif
