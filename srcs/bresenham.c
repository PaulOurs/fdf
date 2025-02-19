/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 03:25:29 by paubello          #+#    #+#             */
/*   Updated: 2025/02/18 23:43:09 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
    ft_drawline(img, (t_point3D){50, 200, 0, red}, (t_point3D){300, 200, 0, red}, red);

    // 2. Horizontal Line (right to left) - Green
    ft_drawline(img, (t_point3D){300, 200, 0, green}, (t_point3D){50, 200, 0, green}, green);

    // 3. Vertical Line (top to bottom) - Blue
    ft_drawline(img, (t_point3D){200, 50, 0, blue}, (t_point3D){200, 400, 0, blue}, blue);

    // 4. Vertical Line (bottom to top) - Yellow
    ft_drawline(img, (t_point3D){200, 400, 0, yellow}, (t_point3D){200, 50, 0, yellow}, yellow);

    // 5. Shallow Slope (dx > dy, positive slope) - Cyan
    ft_drawline(img, (t_point3D){100, 100, 0, cyan}, (t_point3D){400, 150, 0, cyan}, cyan);

    // 6. Steep Slope (dy > dx, positive slope) - Magenta
    ft_drawline(img, (t_point3D){100, 100, 0, magenta}, (t_point3D){150, 400, 0, magenta}, magenta);

    // 7. Negative Slope (downward, left-to-right) - White
    ft_drawline(img, (t_point3D){100, 400, 0, white}, (t_point3D){400, 100, 0, white}, white);

    // 8. Negative Slope (downward, right-to-left) - Orange
    ft_drawline(img, (t_point3D){400, 100, 0, orange}, (t_point3D){100, 400, 0, orange}, orange);

    // 9. Single Point (Edge Case) - Purple
    ft_drawline(img, (t_point3D){250, 250, 0, purple}, (t_point3D){250, 250, 0, purple}, purple);

    // 10. Very Steep Line - Pink
    ft_drawline(img, (t_point3D){300, 50, 0, pink}, (t_point3D){305, 400, 0, pink}, pink);

    // 11. Very Shallow Line - Gray
    ft_drawline(img, (t_point3D){50, 300, 0, gray}, (t_point3D){400, 305, 0, gray}, gray);

    __builtin_printf("Tests completed.\n");
}

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
