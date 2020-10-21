/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <yalona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:04:32 by yalona           #+#    #+#             */
/*   Updated: 2020/03/04 12:28:01 by yalona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_x(int *y, int *z, double x_angle, t_fdf *fdf)
{
	int previous_y;

	previous_y = *y;
	*y = (int)(previous_y * cos(x_angle * fdf->projection) + *z *
			sin(x_angle * fdf->projection));
	*z = (int)(-previous_y * sin(x_angle * fdf->projection) + *z *
			cos(x_angle * fdf->projection));
}

void	rotate_y(int *x, int *z, double y_angle, t_fdf *fdf)
{
	int previous_x;

	previous_x = *x;
	*x = (int)(previous_x * cos(y_angle * fdf->projection) + *z *
			sin(y_angle * fdf->projection));
	*z = (int)(-previous_x * sin(y_angle * fdf->projection) + *z *
			cos(y_angle * fdf->projection));
}

void	rotate_z(int *x, int *y, double z_angle)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (int)(previous_x * cos(z_angle) - previous_y * sin(z_angle));
	*y = (int)(previous_x * sin(z_angle) + previous_y * cos(z_angle));
}
