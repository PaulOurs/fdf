/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 04:22:12 by paubello          #+#    #+#             */
/*   Updated: 2025/02/16 06:19:54 by paubello         ###   ########.fr       */
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

int	get_abs(int val)
{
	if (val < 0)
		return(-val);
	return (val);
}

void	ft_drawline(t_data img, t_point3D p1, t_point3D p2, int color)
{
	int dx = get_abs(p2.x - p1.x);
	int dy = get_abs(p2.y - p1.y);
	int sx = (p1.x < p2.x) ? 1 : -1; // Step in x direction
	int sy = (p1.y < p2.y) ? 1 : -1; // Step in y direction
	int err = dx - dy;
	int  e2;

	while (1)
	{
		ft_put_pixel(&img, p1.x, p1.y, color); // Draw pixel

		if (p1.x == p2.x && p1.y == p2.y) // Stop when reaching the endpoint
			break;

		e2 = 2 * err;
		if (e2 > -dy) // Move in x direction
		{
			err -= dy;
			p1.x += sx;
		}
		if (e2 < dx) // Move in y direction
		{
			err += dx;
			p1.y += sy;
		}
	}
}

void run_tests(t_data img)
{
    __builtin_printf("Running Bresenham line tests with colors...\n");

    // Define colors
    int red = 0x00FF0000;
    int green = 0x0000FF00;
    int blue = 0x000000FF;
    int yellow = 0x00FFFF00;
    int cyan = 0x0000FFFF;
    int magenta = 0x00FF00FF;
    int white = 0x00FFFFFF;
    int orange = 0x00FFA500;
    int purple = 0x00800080;
    int pink = 0x00FFC0CB;
    int gray = 0x00808080;

    // 1. Horizontal Line (left to right) - Red
    ft_drawline(img, (t_point3D){50, 200, 0}, (t_point3D){300, 200, 0}, red);

    // 2. Horizontal Line (right to left) - Green
    ft_drawline(img, (t_point3D){300, 200, 0}, (t_point3D){50, 200, 0}, green);

    // 3. Vertical Line (top to bottom) - Blue
    ft_drawline(img, (t_point3D){200, 50, 0}, (t_point3D){200, 400, 0}, blue);

    // 4. Vertical Line (bottom to top) - Yellow
    ft_drawline(img, (t_point3D){200, 400, 0}, (t_point3D){200, 50, 0}, yellow);

    // 5. Shallow Slope (dx > dy, positive slope) - Cyan
    ft_drawline(img, (t_point3D){100, 100, 0}, (t_point3D){400, 150, 0}, cyan);

    // 6. Steep Slope (dy > dx, positive slope) - Magenta
    ft_drawline(img, (t_point3D){100, 100, 0}, (t_point3D){150, 400, 0}, magenta);

    // 7. Negative Slope (downward, left-to-right) - White
    ft_drawline(img, (t_point3D){100, 400, 0}, (t_point3D){400, 100, 0}, white);

    // 8. Negative Slope (downward, right-to-left) - Orange
    ft_drawline(img, (t_point3D){400, 100, 0}, (t_point3D){100, 400, 0}, orange);

    // 9. Single Point (Edge Case) - Purple
    ft_drawline(img, (t_point3D){250, 250, 0}, (t_point3D){250, 250, 0}, purple);

    // 10. Very Steep Line - Pink
    ft_drawline(img, (t_point3D){300, 50, 0}, (t_point3D){305, 400, 0}, pink);

    // 11. Very Shallow Line - Gray
    ft_drawline(img, (t_point3D){50, 300, 0}, (t_point3D){400, 305, 0}, gray);

    __builtin_printf("Tests completed.\n");
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

	run_tests(img);

	mlx_put_image_to_window(mlx, win, img.img, 0, 0);

	mlx_loop(mlx);
	return (0);
}
