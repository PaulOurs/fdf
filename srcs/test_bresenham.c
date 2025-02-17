/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bresenham.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 03:25:29 by paubello          #+#    #+#             */
/*   Updated: 2025/02/17 03:30:10 by paubello         ###   ########.fr       */
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
