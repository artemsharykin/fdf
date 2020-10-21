/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <yalona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 10:50:19 by yalona           #+#    #+#             */
/*   Updated: 2020/03/11 10:47:18 by yalona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "../Libft/libft.h"
# define COLOR_B	0x00001a41
# define COLOR_E	0x00FFF68F
# define COLOR_B_1	0x00460000
# define COLOR_E_1	0x00FFFFFF
# define COLOR_B_2	0x00003131
# define COLOR_E_2	0x00b81b6c
# define COLOR_B_3	0x002d004e
# define COLOR_E_3	0x00e56c19
# define COLOR_TEXT	0x87ceeb

typedef struct		s_line
{
	t_point			p1;
	t_point			p2;
}					t_line;

typedef	struct		s_cam
{
	double			x_angle;
	double			y_angle;
	double			z_angle;
}					t_cam;

typedef struct		s_grad
{
	int				begin;
	int				end;
	int				bull;
}					t_grad;

typedef struct		s_fdf
{
	t_point			begin;
	int				pix_x;
	int				pix_y;
	void			*ptr;
	void			*window;
	void			*menu_ptr;
	void			*canvas_ptr;
	char			*addr_menu;
	char			*addr_canvas;
	int				bits;
	int				line_size;
	int				endian;
	int				bits_can;
	int				line_size_can;
	int				endian_can;
	int				x;
	int				y;
	long			**arr;
	t_point			*arr_point;
	t_point			*initial;
	int				step;
	int				step_y;
	int				step_x;
	double			iso;
	int				max_height;
	int				min_height;
	long			height;
	char			projection;
	double			scale;
	t_cam			*camera;
	t_grad			grad;
	char			***input;
}					t_fdf;

/*
** --------------------------color.c-----------------------------
*/
int					ft_rgb(unsigned char red, unsigned char green,
						unsigned char blue);
int					find_rgb(t_point cur, t_fdf *fdf);
int					ft_grad_y(t_point min, t_point max, int cur);
int					ft_grad_x(t_point min, t_point max, int cur);

/*
** ----------------------primitives.c----------------------------
*/
t_point				iso(t_point a, t_fdf *fdf, char bull);
t_point				init_point(int x, int y, int z);
t_line				*ft_swap_points(t_line *line);
t_point				make_point(int x, int y, int z, int color);

/*
** ------------------------project.c-----------------------------
*/
void				rotate_x(int *y, int *z, double x_angle, t_fdf *fdf);
void				rotate_y(int *x, int *z, double y_angle, t_fdf *fdf);
void				rotate_z(int *x, int *y, double z_angle);

/*
** --------------------------lines.c-----------------------------
*/
long				ft_count_z(long a, t_fdf *fdf);
void				draw_sharp(t_point *p1, t_point *p2,\
		int dir, t_fdf *fdf);
void				draw_narrow(t_point *p1, t_point *p2,\
		int dir, t_fdf *fdf);
void				draw_line_n(t_point a, t_point b, t_fdf *fdf);
void				draw_line_plain(t_point p1, t_point p2,
					int dir, t_fdf *fdf);

/*
** -------------------events_operations.c-------------------------
*/
void				zoom(int key, t_fdf *fdf);
void				move(int key, t_fdf *fdf);
void				rotate(int key, t_fdf *fdf);
void				ft_viewpoint(int key, t_fdf *fdf);

/*
** -------------------events_operations_2.c-----------------------
*/
int					ft_close(void *param);
void				ft_scale(int key, t_fdf *fdf);
void				ft_change_grad(int key, t_fdf *fdf);
void				back_to_origin(int key, t_fdf *fdf);

/*
** --------------------------draw.c-------------------------------
*/
void				ft_draw_map_arr(t_fdf *fdf);
t_point				pr_point(t_point p, t_fdf *fdf);
void				put_pixel(t_fdf *fdf, int x, int y, int color);

/*
** ------------------------draw_menu.c-----------------------------
*/
void				ft_draw_menu(t_fdf *fdf);
void				ft_text_menu(t_fdf *fdf);
void				ft_text_menu_2(t_fdf *fdf);
void				ft_text_menu_3(t_fdf *fdf);

/*
** ---------------------------init.c-------------------------------
*/
void				ft_count_scale(t_fdf *fdf);
int					ft_init(t_fdf *fdf);
int					ft_set_array(t_fdf *fdf);
int					ft_set_points_arr(t_fdf *fdf);
int					ft_set_initial_arr(t_fdf *fdf);

/*
** ---------------------------events.c------------------------------
*/
void				ft_event_listener(t_fdf *fdf);
int					key_press(int key, void *param);
int					mouse_press(int button, int x, int y, void *param);

/*
** --------------------------input_read.c---------------------------
*/
int					ft_count_width(char *line);
int					ft_read_input(int fd, t_fdf *fdf);
void				ft_set_initial_colors(t_fdf *fdf);
void				ft_set_colors(t_fdf *fdf);

/*
** ----------------------------validate.c---------------------------
*/
int					ft_is_num(char *s);
int					ft_count_minmax(t_fdf *fdf);
int					ft_validate_input(char *line, t_fdf *fdf, int width, int i);
int					ft_check_map(int fd, t_fdf *fdf);
int					ft_is_large(t_fdf *fdf);

/*
** ---------------------------exit_free.c---------------------------
*/
void				free_long_arr(long ***arr, int size_y);
void				terminate_gnl(t_fdf *fdf, char *str, char **line);
void				terminate_fdf(t_fdf *fdf, char *str);
void				free_char_arr(char ****arr, int size_y, int size_x);
void				free_char_ar(char ***arr, int size_y);
#endif
