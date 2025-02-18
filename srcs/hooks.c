/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 04:14:49 by paubello          #+#    #+#             */
/*   Updated: 2025/02/18 05:37:12 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// Handle key presses (Exit on ESC)
int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC) // Escape key (Linux/X11)
	{
		printf("Escape key pressed. Exiting...\n");
		free_display(vars);
		return (0);
	}
	else if (keycode == KEY_SPACE)
	{
		printf("Space key pressed. YAY !!!\n");
		return (0);
	}
	return (0);
}

int	init_hooks(t_vars *vars)
{
	// Handle key events
	mlx_hook(vars->win, 2, 1L << 0, key_hook, vars);
	// Handle window close event (DestroyNotify)
	mlx_hook(vars->win, CLOSE_WINDOW, 0, free_display, vars);
	return (0);
}
