/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 03:20:10 by paubello          #+#    #+#             */
/*   Updated: 2025/02/17 05:43:35 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_data;

typedef struct s_point3D
{
	int	x;
	int	y;
	int	z;
}	t_point3D;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	*img;
}	t_vars;

void	ft_drawline(t_data img, t_point3D p1, t_point3D p2, int color);
void	run_tests(t_data img);

int		init_hooks(t_vars *vars);
int		close_window(t_vars *vars);
void	close_mlx(t_vars *vars);

void	free_display(t_vars *vars);

#endif
