/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 06:01:57 by paubello          #+#    #+#             */
/*   Updated: 2025/02/16 06:45:22 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <math.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int	test;
}	t_vars;


typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_data;

int	key_hook(int keycode, t_vars *vars)
{
	// (void)vars;
	(void)keycode;
	vars->test = 1;
	__builtin_printf("Encore envie de chier");
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Envie de chier");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
