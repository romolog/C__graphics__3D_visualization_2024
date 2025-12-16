/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_6_xiaolinwu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:37:48 by rponomar          #+#    #+#             */
/*   Updated: 2024/11/05 21:36:28 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void	ft_steep(t_dr *d)
{
	d->steep = 0;
	d->abs_x = (d->bx - d->ax) - 2 * (d->bx - d->ax) * ((d->bx - d->ax) < 0);
	d->abs_y = (d->by - d->ay) - 2 * (d->by - d->ay) * ((d->by - d->ay) < 0);
	if (d->abs_y > d->abs_x)
		d->steep = 1;
}

static void	ft_swap_xy(t_dr *d)
{
	int	temp;

	d->axc = d->ax;
	d->ayc = d->ay;
	d->bxc = d->bx;
	d->byc = d->by;
	if (d->steep)
	{
		temp = d->ax;
		d->ax = d->ay;
		d->ay = temp;
		temp = d->bx;
		d->bx = d->by;
		d->by = temp;
	}
	if (d->ax > d->bx)
	{
		temp = d->ax;
		d->ax = d->bx;
		d->bx = temp;
		temp = d->ay;
		d->ay = d->by;
		d->by = temp;
	}
}

static void	ft_gradient(t_dr *d)
{
	if (d->bx - d->ax == 0)
		d->gradient = 1.0;
	else
		d->gradient = ((d->by - d->ay) / (d->bx - d->ax));
}

static void	ft_endpoint(t_dr *d, double x, double y, int first)
{
	d->xend = round(x);
	d->yend = y + d->gradient * (d->xend - x);
	if (first)
		d->xgap = ft_rfpart(x + 0.5);
	else
		d->xgap = (x + 0.5) - floor(x + 0.5);
}

void	ft_xiaolinwu(t_dr *d)
{
	ft_steep(d);
	ft_swap_xy(d);
	ft_gradient(d);
	ft_endpoint(d, d->ax, d->ay, 1);
	d->ax_pxl = (int)d->xend;
	d->ay_pxl = (int)floor(d->yend);
	ft_draw_a_point(d);
	d->intery = d->yend + d->gradient;
	ft_endpoint(d, d->bx, d->by, 0);
	d->bx_pxl = d->xend;
	d->by_pxl = floor(d->yend);
	ft_draw_b_point(d);
	ft_draw_ab_line(d);
}
