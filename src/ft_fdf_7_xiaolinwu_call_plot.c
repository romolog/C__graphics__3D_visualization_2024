/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_7_xiaolinwu_call_plot.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:09:08 by rponomar          #+#    #+#             */
/*   Updated: 2024/11/05 21:36:44 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

double	ft_rfpart(double x)
{
	return (1 - (x - floor(x)));
}

void	ft_draw_a_point(t_dr *d)
{
	if (d->steep)
	{
		ft_plot(d->ay_pxl, d->ax_pxl, ft_rfpart(d->yend) * d->xgap, d);
		ft_plot(d->ay_pxl + 1, d->ax_pxl, \
			(d->yend - floor(d->yend)) * d->xgap, d);
	}
	else
	{
		ft_plot(d->ax_pxl, d->ay_pxl, ft_rfpart(d->yend) * d->xgap, d);
		ft_plot(d->ax_pxl, d->ay_pxl + 1, \
			(d->yend - floor(d->yend)) * d->xgap, d);
	}
}

void	ft_draw_b_point(t_dr *d)
{
	if (d->steep)
	{
		ft_plot(d->by_pxl, d->bx_pxl, ft_rfpart(d->yend) * d->xgap, d);
		ft_plot(d->by_pxl + 1, d->bx_pxl, \
			(d->yend - floor(d->yend)) * d->xgap, d);
	}
	else
	{
		ft_plot(d->bx_pxl, d->by_pxl, ft_rfpart(d->yend) * d->xgap, d);
		ft_plot(d->bx_pxl, d->by_pxl + 1, \
			(d->yend - floor(d->yend)) * d->xgap, d);
	}
}

void	ft_draw_ab_line(t_dr *d)
{
	double	i;

	i = d->ax_pxl;
	while (d->steep && ++i < d->bx_pxl)
	{
		ft_plot(floor(d->intery), i, ft_rfpart(d->intery), d);
		ft_plot(floor(d->intery) + 1, i, d->intery - floor(d->intery), d);
		d->intery = d->intery + d->gradient;
	}
	while (!d->steep && ++i < d->bx_pxl)
	{
		ft_plot(i, floor(d->intery), ft_rfpart(d->intery), d);
		ft_plot(i, floor(d->intery) + 1, d->intery - floor(d->intery), d);
		d->intery = d->intery + d->gradient;
	}
}
