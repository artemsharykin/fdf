/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <yalona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:01:47 by yalona           #+#    #+#             */
/*   Updated: 2020/03/10 15:10:26 by yalona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	pr_point(t_point p, t_fdf *fdf)
{
	rotate_x(&p.y, &p.z, fdf->camera->x_angle, fdf);
	rotate_y(&p.x, &p.z, fdf->camera->y_angle, fdf);
	rotate_z(&p.x, &p.y, fdf->camera->z_angle);
	p = iso(p, fdf, fdf->projection);
	return (p);
}

void	ft_draw_canvas(t_fdf *fdf)
{
	int		k;
	int		*temp;

	fdf->canvas_ptr = mlx_new_image(fdf->ptr, 0.75 * (fdf->pix_x), fdf->pix_y);
	fdf->addr_canvas = mlx_get_data_addr(fdf->canvas_ptr, &fdf->bits_can,
			&fdf->line_size_can, &fdf->endian_can);
	k = 0;
	temp = (int *)(fdf->addr_canvas);
	while (k < 0.75 * (fdf->pix_x) * fdf->pix_y)
	{
		temp[k] = ft_rgb(0x00, 0x00, 0x00);
		k++;
	}
}

void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < (fdf->pix_x * 0.75) && y >= 0 && y < fdf->pix_y)
	{
		i = (x * fdf->bits_can / 8) + (y * fdf->line_size_can);
		fdf->addr_canvas[i] = color;
		fdf->addr_canvas[++i] = color >> 8;
		fdf->addr_canvas[++i] = color >> 16;
	}
}

void	ft_draw_map_arr_2(t_fdf *fdf, int i, t_point a)
{
	int		j;

	j = 0;
	while (j < fdf->x - 1)
	{
		draw_line_n(pr_point(a, fdf),
				pr_point(fdf->arr_point[i * fdf->x + j + 1], fdf), fdf);
		a = fdf->arr_point[i * fdf->x + j + 1];
		j++;
	}
	mlx_put_image_to_window(fdf->ptr, fdf->window, fdf->canvas_ptr, 0, 0);
	ft_draw_menu(fdf);
}

void	ft_draw_map_arr(t_fdf *fdf)
{
	int		i;
	int		j;
	t_point	a;

	a = fdf->arr_point[0];
	i = -1;
	mlx_clear_window(fdf->ptr, fdf->window);
	ft_draw_canvas(fdf);
	while (++i < fdf->y - 1)
	{
		j = 0;
		while (j < fdf->x - 1)
		{
			draw_line_n(pr_point(a, fdf),
					pr_point(fdf->arr_point[i * fdf->x + j + 1], fdf), fdf);
			draw_line_n(pr_point(a, fdf),
					pr_point(fdf->arr_point[(i + 1) * fdf->x + j], fdf), fdf);
			a = fdf->arr_point[i * fdf->x + j + 1];
			j++;
		}
		draw_line_n(pr_point(a, fdf),
				pr_point(fdf->arr_point[(i + 1) * fdf->x + j], fdf), fdf);
		a = fdf->arr_point[(i + 1) * fdf->x];
	}
	ft_draw_map_arr_2(fdf, i, a);
}
