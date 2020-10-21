/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <yalona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 10:58:56 by yalona           #+#    #+#             */
/*   Updated: 2020/03/11 11:33:53 by yalona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/exit_messages.h"

int		ft_is_num(char *s)
{
	char	*temp1;
	char	*temp2;

	if (!(temp1 = ft_itoa(ft_atoi(s))))
		return (0);
	if (!(temp2 = ft_itoa_sign(ft_atoi(s))))
	{
		free(temp1);
		return (0);
	}
	if ((ft_strcmp(temp1, s) == 0) || ft_strcmp(temp2, s) == 0)
	{
		free(temp1);
		free(temp2);
		return (1);
	}
	free(temp1);
	free(temp2);
	return (0);
}

int		ft_is_large(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->y)
	{
		j = 0;
		while (j < fdf->x)
		{
			if (fdf->arr[i][j] > 2147483647 ||
				fdf->arr[i][j] < -2147483648)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_count_minmax(t_fdf *fdf)
{
	if ((ft_min_double_arr(fdf->arr, fdf->x, fdf->y)) == 3000000000)
		return (0);
	else
		fdf->min_height = (int)ft_min_double_arr(fdf->arr, fdf->x, fdf->y);
	if ((ft_max_double_arr(fdf->arr, fdf->x, fdf->y)) == 3000000000)
		return (0);
	else
		fdf->max_height = (int)ft_max_double_arr(fdf->arr, fdf->x, fdf->y);
	return (1);
}

int		ft_validate_input(char *line, t_fdf *fdf, int width, int j)
{
	int		i;
	char	**arr;

	if (!(arr = ft_strsplit(line, ' ')))
		return (0);
	i = 0;
	while (i < width)
	{
		if (!(ft_is_num(arr[i])))
		{
			free_char_ar(&arr, width);
			return (0);
		}
		i++;
	}
	fdf->input[j] = arr;
	return (1);
}

int		ft_check_map(int fd, t_fdf *fdf)
{
	char	*line;
	int		width;
	int		prev_width;

	fdf->y = 0;
	line = NULL;
	if ((get_next_line(fd, &line)) <= 0)
		terminate_fdf(fdf, EMPTY_FILE);
	width = ft_count_width(line);
	prev_width = width;
	if (!(fdf->x = width))
		terminate_gnl(fdf, MAP_ERROR, &line);
	ft_strdel(&line);
	fdf->y++;
	while ((get_next_line(fd, &line)))
	{
		if (((width = ft_count_width(line)) != prev_width) && prev_width >= 0)
			terminate_gnl(fdf, MAP_ERROR, &line);
		prev_width = width;
		if (!(fdf->x = width))
			terminate_gnl(fdf, MAP_ERROR, &line);
		ft_strdel(&line);
		fdf->y++;
	}
	return (1);
}
