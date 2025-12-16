/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:29:22 by rponomar          #+#    #+#             */
/*   Updated: 2024/11/05 21:47:23 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h> // perror
# include <limits.h> // event_mask INT-MAX 
# include <stdint.h> // int32_t
# include <fcntl.h> // open
# include <math.h> 

# define M_PI 3.14159265358979323846
# define FT_ESC_CODE 65307

typedef long long			t_ll;

typedef struct s_draw_set
{
	void		*mlx;
	void		*win;
	int			wdth;
	int			hght;
	void		*img;	
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	double		abs_x;
	double		abs_y;
	int			y_min;
	int			y_max;
	double		step;
	double		ax;
	double		axc;
	double		ay;
	double		ayc;
	double		bx;
	double		bxc;
	double		by;
	double		byc;
	int			steep;
	double		gradient;
	double		xend;
	double		yend;
	double		xgap;
	double		intery;
	int			ax_pxl;
	int			ay_pxl;
	int			bx_pxl;
	int			by_pxl;
	t_ll		color_a;
	t_ll		color_b;
}	t_dr;

typedef struct s_tracker
{
	t_dr		*d;
	int			**map;
	int			map_len;
	int			map_rows;
	int			map_base;
	t_ll		**color;
	uint32_t	color_min;
	uint32_t	color_max;
	int			color_dflt;
}	t_tr;

void		ft_destroy_free(t_tr *t, t_dr *d);
void		ft_draw_image(t_tr *t, t_dr *d);
void		ft_draw_lines(t_tr *t, t_dr *d);
void		ft_draw_a_point(t_dr *d);
void		ft_draw_ab_line(t_dr *d);
void		ft_draw_b_point(t_dr *d);
void		ft_error_message(int n, t_tr *t, t_dr *d);
void		ft_get_map(char *file_name, t_tr *t);
void		ft_plot(int x, int y, double bright, t_dr *d);
void		ft_put_row_to_map(char *str, t_tr *t);
double		ft_rfpart(double x);
void		ft_set_color(t_tr *t);
void		ft_xiaolinwu(t_dr *d);

#endif

//void		ft_print_2d(t_tr *t);
