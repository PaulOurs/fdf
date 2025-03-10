/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 04:13:58 by paubello          #+#    #+#             */
/*   Updated: 2025/02/18 02:56:26 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	free_display(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img->img);\
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}
