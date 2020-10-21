/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <yalona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:55:13 by yalona           #+#    #+#             */
/*   Updated: 2020/03/11 14:10:48 by yalona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/key_codes.h"

void	zoom(int key, t_fdf *fdf)
{
	if (key == MOUSE_SCROLL_UP || key == NUM_PAD_PLUS)
		fdf->step += 5;
	else if (key == MOUSE_SCROLL_DOWN || key == NUM_PAD_MINUS)
		fdf->step -= 5;
	if (fdf->step < 1)
	{
		fdf->step = 2;
	}
	ft_set_points_arr(fdf);
	ft_draw_map_arr(fdf);
}

void	move(int key, t_fdf *fdf)
{
	if (key == ARR_RIGHT)
		fdf->begin.x += 10;
	if (key == ARR_LEFT)
		fdf->begin.x -= 10;
	if (key == ARR_UP)
		fdf->begin.y -= 10;
	if (key == ARR_DOWN)
		fdf->begin.y += 10;
	ft_draw_map_arr(fdf);
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == NUM_PAD_9)
		fdf->camera->x_angle += 0.02;
	else if (key == NUM_PAD_7)
		fdf->camera->x_angle -= 0.02;
	else if (key == NUM_PAD_6)
		fdf->camera->y_angle += 0.02;
	else if (key == NUM_PAD_4)
		fdf->camera->y_angle -= 0.02;
	else if (key == NUM_PAD_3)
		fdf->camera->z_angle += 0.02;
	else if (key == NUM_PAD_1)
		fdf->camera->z_angle -= 0.02;
	ft_set_points_arr(fdf);
	ft_draw_map_arr(fdf);
}

void	ft_viewpoint(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_I)
		fdf->projection = 1;
	if (key == MAIN_PAD_P)
		fdf->projection = 0;
	ft_set_points_arr(fdf);
	ft_draw_map_arr(fdf);
}
