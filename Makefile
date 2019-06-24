# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roduquen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/19 19:33:43 by roduquen          #+#    #+#              #
#    Updated: 2019/06/24 13:01:21 by roduquen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = bsq
SRCDIR = ./srcs/
INCLDIR = ./includes/
SRCS =	$(SRCDIR)ft_first.c $(SRCDIR)ft_load_result.c $(SRCDIR)ft_memory.c \
		$(SRCDIR)ft_min.c $(SRCDIR)ft_solveur_bsq.c $(SRCDIR)ft_bsq.c \
		$(SRCDIR)ft_charset.c $(SRCDIR)ft_print_soluce.c $(SRCDIR)ft_start.c \
		$(SRCDIR)main.c $(SRCDIR)ft_count.c $(SRCDIR)ft_bsq_stdin.c \
		$(SRCDIR)ft_print_stdin.c $(SRCDIR)ft_stdin.c $(SRCDIR)ft_swap.c \
		$(SRCDIR)ft_strjoin.c
OBJS = $(SRCS:.c=.o)
OBJS_ = $(notdir $(OBJS))

all : $(NAME)

$(NAME) : $(OBJS_)
			$(CC) $(CFLAGS) $(OBJS_) -o $(NAME)

$(OBJS_) : $(SRCS) $(INCLUDES)
			$(CC) $(CFLAGS) -c -I $(INCLDIR) $(SRCS)

clean :
			rm -rf $(OBJS_)

fclean : clean
			rm -rf $(NAME)

re : fclean all
