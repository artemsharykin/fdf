/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <yalona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:24:10 by yalona           #+#    #+#             */
/*   Updated: 2020/03/04 10:50:39 by yalona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/key_codes.h"

void	ft_event_listener(t_fdf *fdf)
{
	mlx_hook(fdf->window, 2, 0, key_press, fdf);
	mlx_hook(fdf->window, 17, 0, ft_close, fdf);
	mlx_hook(fdf->window, 4, 0, mouse_press, fdf);
}

int		key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == MAIN_PAD_ESC)
		terminate_fdf(fdf, "Thank you for the check :)");
	if (key == NUM_PAD_PLUS || key == NUM_PAD_MINUS)
		zoom(key, fdf);
	else if (key == ARR_LEFT || key == ARR_RIGHT
			|| key == ARR_UP || key == ARR_DOWN)
		move(key, fdf);
	else if (key == NUM_PAD_1 || key == NUM_PAD_3
			|| key == NUM_PAD_4 || key == NUM_PAD_6
			|| key == NUM_PAD_7 || key == NUM_PAD_9)
		rotate(key, fdf);
	else if (key == MAIN_PAD_I || key == MAIN_PAD_P)
		ft_viewpoint(key, fdf);
	else if (key == MAIN_PAD_O)
		back_to_origin(key, fdf);
	else if (key == NUM_PAD_2	|| key == NUM_PAD_8)
		ft_scale(key, fdf);
	else if (key == MAIN_PAD_1 || key == MAIN_PAD_2
			|| key == MAIN_PAD_3 || key == MAIN_PAD_4)
		ft_change_grad(key, fdf);
	return (0);
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		zoom(button, fdf);
	return (0);
}
