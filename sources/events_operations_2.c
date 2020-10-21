/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_operations_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <yalona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:44:11 by yalona           #+#    #+#             */
/*   Updated: 2020/03/10 15:11:43 by yalona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/key_codes.h"

int		ft_close(void *param)
{
	terminate_fdf((t_fdf *)param, "Thank you for the check :)");
	return (0);
}

void	ft_scale(int key, t_fdf *fdf)
{
	if (key == NUM_PAD_8)
		fdf->scale += 0.2;
	else
	{
		fdf->scale -= 0.2;
		if (fdf->scale < 0)
			fdf->scale = 0;
	}
	ft_set_points_arr(fdf);
	ft_draw_map_arr(fdf);
}

void	ft_change_grad(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_1)
	{
		fdf->grad.begin = COLOR_B;
		fdf->grad.end = COLOR_E;
	}
	if (key == MAIN_PAD_2)
	{
		fdf->grad.begin = COLOR_B_1;
		fdf->grad.end = COLOR_E_1;
	}
	if (key == MAIN_PAD_3)
	{
		fdf->grad.begin = COLOR_B_2;
		fdf->grad.end = COLOR_E_2;
	}
	if (key == MAIN_PAD_4)
	{
		fdf->grad.begin = COLOR_B_3;
		fdf->grad.end = COLOR_E_3;
	}
	ft_set_initial_colors(fdf);
	ft_set_colors(fdf);
	ft_draw_map_arr(fdf);
}

void	back_to_origin(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_O)
	{
		fdf->camera->x_angle = 0;
		fdf->camera->y_angle = 0;
		fdf->camera->z_angle = 0;
		fdf->begin = init_point(fdf->pix_x * 0.3, fdf->pix_y * 0.1, 0);
		fdf->step = (0.6 * fdf->pix_x) / fdf->x;
		fdf->step_x = fdf->step;
		fdf->step_y = fdf->step;
		ft_count_scale(fdf);
		if (fdf->grad.bull)
		{
			fdf->grad.begin = COLOR_B;
			fdf->grad.end = COLOR_E;
		}
		ft_set_initial_colors(fdf);
		ft_set_points_arr(fdf);
		ft_draw_map_arr(fdf);
	}
}
