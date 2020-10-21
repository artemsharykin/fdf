/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <yalona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:46:58 by yalona           #+#    #+#             */
/*   Updated: 2020/03/11 11:13:55 by yalona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/exit_messages.h"

void	ft_count_scale(t_fdf *fdf)
{
	if (fdf->height == 0)
		fdf->scale = 1;
	else if ((int)fdf->height >= fdf->pix_y)
		fdf->scale = (((double)fdf->pix_y * 0.3) /
				(double)(fdf->height) / (double)fdf->step);
	else
		fdf->scale = (((double)fdf->pix_y * 0.3) /
				(double)(fdf->height) / (double)fdf->step);
}

int		ft_init(t_fdf *fdf)
{
	fdf->ptr = mlx_init();
	fdf->pix_x = 1280;
	fdf->pix_y = 720;
	fdf->window = mlx_new_window(fdf->ptr, fdf->pix_x, fdf->pix_y, "FDF");
	fdf->begin = init_point(fdf->pix_x * 0.3, fdf->pix_y * 0.1, 0);
	fdf->step = (0.6 * fdf->pix_x) / fdf->x;
	fdf->step_x = fdf->step;
	fdf->step_y = fdf->step;
	if (!ft_count_minmax(fdf))
		return (0);
	fdf->height = fdf->max_height - fdf->min_height;
	ft_count_scale(fdf);
	fdf->iso = 0.523599;
	fdf->camera = (t_cam *)malloc(sizeof(t_cam));
	fdf->camera->x_angle = 0;
	fdf->camera->y_angle = 0;
	fdf->camera->z_angle = 0;
	fdf->grad.begin = COLOR_B;
	fdf->grad.end = COLOR_E;
	fdf->projection = 1;
	fdf->grad.bull = 1;
	return (1);
}

int		ft_set_initial_arr(t_fdf *fdf)
{
	int i;
	int j;

	if (fdf->initial)
		free(&fdf->initial);
	if (!(fdf->initial = (t_point *)malloc(sizeof(t_point) *
			fdf->y * fdf->x)))
		terminate_fdf(fdf, FDF_ERROR);
	i = 0;
	while (i < fdf->y)
	{
		j = 0;
		while (j < fdf->x)
		{
			fdf->initial[i * fdf->x + j] = init_point(j * fdf->step,
					i * fdf->step, (int)ft_count_z(fdf->arr[i][j], fdf));
			j++;
		}
		i++;
	}
	ft_set_initial_colors(fdf);
	return (1);
}

int		ft_set_points_arr(t_fdf *fdf)
{
	int i;
	int j;

	if (fdf->arr_point)
		free(fdf->arr_point);
	if (!(fdf->arr_point = (t_point *)malloc(sizeof(t_point) *
			fdf->y * fdf->x)))
		terminate_fdf(fdf, FDF_ERROR);
	i = 0;
	while (i < fdf->y)
	{
		j = 0;
		while (j < fdf->x)
		{
			fdf->arr_point[i * fdf->x + j] = init_point(j * fdf->step,
					i * fdf->step, (int)ft_count_z(fdf->arr[i][j], fdf));
			j++;
		}
		i++;
	}
	ft_set_colors(fdf);
	return (1);
}

int		ft_set_array(t_fdf *fdf)
{
	int i;
	int j;

	if (fdf->arr)
		free_long_arr(&fdf->arr, fdf->y);
	if (!(fdf->arr = (long **)malloc(sizeof(long *) * fdf->y)))
		return (0);
	i = 0;
	while (i < fdf->y)
	{
		if (!(fdf->arr[i] = (long *)malloc(sizeof(long) * fdf->x)))
			return (0);
		i++;
	}
	i = -1;
	while (++i < fdf->y)
	{
		j = 0;
		while (j < fdf->x)
		{
			fdf->arr[i][j] = (long)ft_atoi(fdf->input[i][j]);
			j++;
		}
	}
	return (1);
}
