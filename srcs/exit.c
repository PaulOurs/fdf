/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 04:13:58 by paubello          #+#    #+#             */
/*   Updated: 2025/02/17 06:15:51 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	close_mlx(t_vars *vars)
{
	free_display(vars);
	exit(0);
}

// Handle window close button
int	close_window(t_vars *vars)
{
	printf("Window close button clicked. Exiting...\n");
	close_mlx(vars);
	return (0);
}
