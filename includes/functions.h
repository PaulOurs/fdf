/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 02:49:41 by paubello          #+#    #+#             */
/*   Updated: 2025/02/18 05:35:33 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/*			Drawing functions			*/

void	ft_drawline(t_data img, t_point3D p1, t_point3D p2, int color);
void	run_tests(t_data img);
int		get_abs(int val);


typedef struct s_data	t_data;
typedef struct s_point3D	t_point3D;
typedef struct s_vars	t_vars;

#endif
