/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 03:20:10 by paubello          #+#    #+#             */
/*   Updated: 2025/02/19 04:02:46 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libs/minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define WIDTH 1920
# define HEIGHT 1080

 #include "structure.h"
 #include "functions.h"
 #include "keys.h"

int	init_hooks(t_vars *vars);

int	free_display(t_vars *vars);

typedef struct s_data	t_data;
typedef struct s_point3D	t_point3D;
typedef struct s_map	t_map;
typedef struct s_vars	t_vars;

#endif
