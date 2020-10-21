/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <yalona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:09:58 by yalona           #+#    #+#             */
/*   Updated: 2020/03/10 12:15:21 by yalona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/exit_messages.h"

int		ft_count_width(char *line)
{
	int		width;
	size_t	i;

	if (!line)
		return (0);
	width = 0;
	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] != ' ' && line[i])
		{
			width++;
			while (line[i] != ' ' && line[i])
				i++;
		}
	}
	return (width);
}

void	ft_set_initial_colors(t_fdf *fdf)
{
	int		i;

	i = 0;
	fdf->min_height = (int)ft_min_point_arr(fdf->initial, fdf->x * fdf->y);
	fdf->max_height = (int)ft_max_point_arr(fdf->initial, fdf->x * fdf->y);
	while (i < fdf->x * fdf->y)
	{
		fdf->initial[i].color = find_rgb(fdf->initial[i], fdf);
		i++;
	}
}

void	ft_set_colors(t_fdf *fdf)
{
	int		i;

	i = 0;
	while (i < fdf->x * fdf->y)
	{
		fdf->arr_point[i].color = fdf->initial[i].color;
		i++;
	}
}

int		ft_read_input(int fd, t_fdf *fdf)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	if (!(fdf->input = (char ***)malloc(sizeof(char **) * (fdf->y + 1))))
		return (0);
	while ((get_next_line(fd, &line)))
	{
		if (!(ft_validate_input(line, fdf, fdf->x, i)))
		{
			fdf->input[i] = NULL;
			free(line);
			terminate_fdf(fdf, MAP_ERROR);
		}
		ft_strdel(&line);
		i++;
	}
	fdf->input[fdf->y] = NULL;
	return (1);
}
