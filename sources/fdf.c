/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <yalona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:48:33 by yalona           #+#    #+#             */
/*   Updated: 2020/03/10 15:48:40 by yalona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/exit_messages.h"

int		main(int argc, char **argv)
{
	t_fdf	fdf;
	int		fd;

	ft_memset(&fdf, 0, sizeof(t_fdf));
	if (argc != 2)
		terminate_fdf(&fdf, USAGE);
	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		terminate_fdf(&fdf, NO_FILE);
	if (!(ft_check_map(fd, &fdf)))
		terminate_fdf(&fdf, MAP_ERROR);
	close(fd);
	if (!(fd = open(argv[1], O_RDONLY)))
		terminate_fdf(&fdf, FDF_ERROR);
	if (!(ft_read_input(fd, &fdf)))
		terminate_fdf(&fdf, MAP_ERROR);
	ft_set_array(&fdf);
	if (!(ft_init(&fdf)))
		terminate_fdf(&fdf, MAP_ERROR);
	ft_set_initial_arr(&fdf);
	ft_set_points_arr(&fdf);
	ft_draw_map_arr(&fdf);
	ft_event_listener(&fdf);
	mlx_loop(fdf.ptr);
}
