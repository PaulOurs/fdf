/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 04:22:12 by paubello          #+#    #+#             */
/*   Updated: 2025/02/18 05:34:05 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_datas(t_vars *vars, t_data *img)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "FDF");
	img->img = mlx_new_image(vars->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_lenght, &img->endian);
	vars->img = img;
}



int	main(void)
{
	t_vars	vars;
	t_data	img;

	init_datas(&vars, &img);

	run_tests(img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

	init_hooks(&vars);
	mlx_loop(vars.mlx);
	printf("Fin du programme\n");
	return (0);
}
