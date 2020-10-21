/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <yalona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 10:57:04 by yalona           #+#    #+#             */
/*   Updated: 2020/03/11 12:00:19 by yalona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/exit_messages.h"

void	free_long_arr(long ***arr, int size_y)
{
	int i;

	if (!(arr) || !(*arr))
		return ;
	i = 0;
	while (i < size_y)
	{
		if (!(*arr)[i])
			return ;
		free((*arr)[i]);
		i++;
	}
	free(*arr);
}

void	free_char_arr(char ****arr, int size_y, int size_x)
{
	int i;
	int j;

	if (!(arr) || !(*arr))
		return ;
	i = 0;
	while (i <= size_y)
	{
		j = 0;
		if (!(*arr)[i])
			return ;
		while (j < size_x)
		{
			if (!((*arr)[i][j]))
				return ;
			free((*arr)[i][j]);
			j++;
		}
		free((*arr)[i]);
		i++;
	}
	free(*arr);
}

void	free_char_ar(char ***arr, int size_y)
{
	int i;

	if (!(arr) || !(*arr))
		return ;
	i = 0;
	while (i < size_y)
	{
		if (!(*arr)[i])
			return ;
		free((*arr)[i]);
		i++;
	}
	free(*arr);
}

void	terminate_fdf(t_fdf *fdf, char *str)
{
	if (fdf->addr_menu)
		free(fdf->addr_menu);
	if (fdf->menu_ptr)
		free(fdf->menu_ptr);
	if (fdf->addr_canvas)
		free(fdf->addr_canvas);
	if (fdf->canvas_ptr)
		free(fdf->canvas_ptr);
	free_long_arr(&fdf->arr, fdf->y);
	if (fdf->arr_point)
		free(fdf->arr_point);
	if (fdf->initial)
		free(fdf->initial);
	free_char_arr(&fdf->input, fdf->y, fdf->x);
	if (fdf->camera)
		free(fdf->camera);
	if (fdf->window)
		free(fdf->window);
	if (fdf->ptr)
		free(fdf->ptr);
	write(1, str, ft_strlen(str));
	exit(0);
}

void	terminate_gnl(t_fdf *fdf, char *str, char **line)
{
	free(*line);
	terminate_fdf(fdf, str);
}
