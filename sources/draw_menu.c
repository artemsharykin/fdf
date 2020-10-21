/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <yalona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:42:36 by yalona           #+#    #+#             */
/*   Updated: 2020/03/04 12:21:20 by yalona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_text_menu_3(t_fdf *fdf)
{
	mlx_string_put(fdf->ptr, fdf->window, 0.80 * (fdf->pix_x), 480,
			COLOR_TEXT, "4. ");
	draw_line_plain(make_point(0.82 * (fdf->pix_x), 490, 0, COLOR_B_3),
			make_point(0.90 * (fdf->pix_x), 490, 0, COLOR_E_3), 1, fdf);
	mlx_string_put(fdf->ptr, fdf->window, 0.77 * (fdf->pix_x), 510, COLOR_TEXT,
			"Z-Scale:");
	mlx_string_put(fdf->ptr, fdf->window, 0.80 * (fdf->pix_x), 530, COLOR_TEXT,
			"Greater: NUM 8");
	mlx_string_put(fdf->ptr, fdf->window, 0.80 * (fdf->pix_x), 550, COLOR_TEXT,
			"Lower:   NUM 2");
	mlx_string_put(fdf->ptr, fdf->window, 0.77 * (fdf->pix_x), 580, COLOR_TEXT,
			"Exit:");
	mlx_string_put(fdf->ptr, fdf->window, 0.80 * (fdf->pix_x), 600, COLOR_TEXT,
			"Esc");
}

void	ft_text_menu_2(t_fdf *fdf)
{
	mlx_string_put(fdf->ptr, fdf->window, 0.80 * (fdf->pix_x), 280, COLOR_TEXT,
			"NUM +, NUM -");
	mlx_string_put(fdf->ptr, fdf->window, 0.77 * (fdf->pix_x), 310, COLOR_TEXT,
			"Change projection:");
	mlx_string_put(fdf->ptr, fdf->window, 0.80 * (fdf->pix_x), 330, COLOR_TEXT,
			"Isometric: I");
	mlx_string_put(fdf->ptr, fdf->window, 0.80 * (fdf->pix_x), 350, COLOR_TEXT,
			"Decart: P");
	mlx_string_put(fdf->ptr, fdf->window, 0.80 * (fdf->pix_x), 370, COLOR_TEXT,
			"Back to initial: O");
	mlx_string_put(fdf->ptr, fdf->window, 0.77 * (fdf->pix_x), 400, COLOR_TEXT,
			"Colors:");
	mlx_string_put(fdf->ptr, fdf->window, 0.80 * (fdf->pix_x), 420, COLOR_TEXT,
			"1. ");
	draw_line_plain(make_point(0.82 * (fdf->pix_x), 430, 0, COLOR_B),
			make_point(0.90 * (fdf->pix_x), 430, 0, COLOR_E), 1, fdf);
	mlx_string_put(fdf->ptr, fdf->window, 0.80 * (fdf->pix_x), 440, COLOR_TEXT,
			"2. ");
	draw_line_plain(make_point(0.82 * (fdf->pix_x), 450, 0, COLOR_B_1),
			make_point(0.90 * (fdf->pix_x), 450, 0, COLOR_E_1), 1, fdf);
	mlx_string_put(fdf->ptr, fdf->window, 0.80 * (fdf->pix_x), 460, COLOR_TEXT,
			"3. ");
	draw_line_plain(make_point(0.82 * (fdf->pix_x), 470, 0, COLOR_B_2),
			make_point(0.90 * (fdf->pix_x), 470, 0, COLOR_E_2), 1, fdf);
	ft_text_menu_3(fdf);
}

void	ft_text_menu(t_fdf *fdf)
{
	mlx_string_put(fdf->ptr, fdf->window, 0.83 * (fdf->pix_x), 20, COLOR_TEXT,
			"HOW TO USE:");
	mlx_string_put(fdf->ptr, fdf->window, 0.77 * (fdf->pix_x), 40, COLOR_TEXT,
			"Move:");
	mlx_string_put(fdf->ptr, fdf->window, 0.80 * (fdf->pix_x), 60, COLOR_TEXT,
			"ARR left");
	mlx_string_put(fdf->ptr, fdf->window, 0.80 * (fdf->pix_x), 80, COLOR_TEXT,
			"ARR right");
	mlx_string_put(fdf->ptr, fdf->window, 0.80 * (fdf->pix_x), 100, COLOR_TEXT,
			"ARR up");
	mlx_string_put(fdf->ptr, fdf->window, 0.80 * (fdf->pix_x), 120, COLOR_TEXT,
			"ARR down");
	mlx_string_put(fdf->ptr, fdf->window, 0.77 * (fdf->pix_x), 150, COLOR_TEXT,
			"Rotate:");
	mlx_string_put(fdf->ptr, fdf->window, 0.80 * (fdf->pix_x), 170, COLOR_TEXT,
			"x: NUM 7, NUM 9");
	mlx_string_put(fdf->ptr, fdf->window, 0.80 * (fdf->pix_x), 190, COLOR_TEXT,
			"y: NUM 4, NUM 6");
	mlx_string_put(fdf->ptr, fdf->window, 0.77 * (fdf->pix_x), 240, COLOR_TEXT,
			"Zoom:");
	mlx_string_put(fdf->ptr, fdf->window, 0.80 * (fdf->pix_x), 260, COLOR_TEXT,
			"Mouse Scroll");
	ft_text_menu_2(fdf);
}

void	ft_draw_menu(t_fdf *fdf)
{
	int k;
	int *temp;

	fdf->menu_ptr = mlx_new_image(fdf->ptr, 0.25 * (fdf->pix_x), fdf->pix_y);
	fdf->addr_menu = mlx_get_data_addr(fdf->menu_ptr,
			&fdf->bits, &fdf->line_size, &fdf->endian);
	k = 0;
	temp = (int *)(fdf->addr_menu);
	while (k < 0.25 * (fdf->pix_x) * fdf->pix_y)
	{
		temp[k] = ft_rgb(25, 25, 25);
		k++;
	}
	mlx_put_image_to_window(fdf->ptr, fdf->window, fdf->menu_ptr,
			0.75 * (fdf->pix_x), 0);
	ft_text_menu(fdf);
}
