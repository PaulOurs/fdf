/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 04:22:12 by paubello          #+#    #+#             */
/*   Updated: 2025/02/17 06:27:32 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_abs(int val)
{
	if (val < 0)
		return(-val);
	return (val);
}

void	ft_drawline(t_data img, t_point3D p1, t_point3D p2, int color)
{
	t_point3D	delta;
	int sx = (p1.x < p2.x) ? 1 : -1; // Step in x direction
	int sy = (p1.y < p2.y) ? 1 : -1; // Step in y direction
	int err;
	int  e2;


	delta.x = get_abs(p2.x - p1.x);
	delta.y = get_abs(p2.y - p1.y);
	err = delta.x - delta.y;
	while (1)
	{
		ft_put_pixel(&img, p1.x, p1.y, color); // Draw pixel

		if (p1.x == p2.x && p1.y == p2.y) // Stop when reaching the endpoint
			break;

		e2 = 2 * err;
		if (e2 > -delta.y) // Move in x direction
		{
			err -= delta.y;
			p1.x += sx;
		}
		if (e2 < delta.x) // Move in y direction
		{
			err += delta.x;
			p1.y += sy;
		}
	}
}

void	init_datas(t_vars *vars, t_data *img)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "FDF");
	img->img = mlx_new_image(vars->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_lenght, &img->endian);
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
