/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 04:22:12 by paubello          #+#    #+#             */
/*   Updated: 2025/02/15 05:51:35 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <math.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_data;

typedef struct s_point3D {
	int	x;
	int	y;
	int	z;
}	t_point3D;

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_drawline(t_data img, t_point3D p1, t_point3D p2)
{
	int	dy;
	int	dx;
	int	d;
	int	x;
	int	y;

	dy = p2.y - p1.y;
	dx = p2.x - p1.x;
	d = 2 * dy - dx;
	x = p1.x;
	y = p1.y;
	while (x <= p2.x)
	{
		ft_put_pixel(&img, x, y, 0x00FF0000);
		x++;
		if (d < 0)
			d += 2 * dy;
		else
		{
			d += 2 * (dy - dx);
			y++;
		}
	}

}

int	main(void)
{
	void	*mlx;
	void	*win;
	t_data	img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "Test Window");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);

	t_point3D p1 = {20, 20, 0};
	t_point3D p2 = {500, 50, 0};

	ft_drawline(img, p1, p2);

	mlx_put_image_to_window(mlx, win, img.img, 0, 0);

	mlx_loop(mlx);
	return (0);
}
