/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 02:42:59 by paubello          #+#    #+#             */
/*   Updated: 2025/02/18 02:43:42 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_data;

typedef struct s_point3D
{
	int	x;
	int	y;
	int	z;
}	t_point3D;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	*img;
}	t_vars;

#endif
