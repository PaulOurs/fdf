# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 02:57:10 by paubello          #+#    #+#              #
#    Updated: 2025/02/12 03:36:03 by paubello         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR = ./srcs
OBJS_DIR = ./objs
INCLUDES = -I./includes

SRCS = $(SRCS_DIR)

NAME = fdf

CC = CC
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

