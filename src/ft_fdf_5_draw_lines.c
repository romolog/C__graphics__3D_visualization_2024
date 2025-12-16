/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_5_draw_lines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:29:30 by rponomar          #+#    #+#             */
/*   Updated: 2024/11/08 16:11:15 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void	ft_lines_ab_ac(int k, int i, t_tr *t, t_dr *d)
{
	double	a;
	int		xx;
	int		zz;

	d->color_a = t->color[k][i];
	a = M_PI / 6;
	xx = i * 2 - (t->map_len - 1);
	zz = (t->map_rows - 1) - k * 2;
	d->ax = (xx - zz) * d->step * cos(a);
	d->ay = t->map[k][i] * d->step + (xx + zz) * d->step * sin(a);
	d->color_b = t->color[k][i + (i < t->map_len - 1)];
	d->bx = ((xx + 2) - zz) * d->step * cos(a);
	d->by = t->map[k][i + (i < t->map_len - 1)] * d->step \
		+ ((xx + 2) + zz) * d->step * sin(a);
	if (i < t->map_len - 1)
		ft_xiaolinwu(d);
	d->ax = (xx - zz) * d->step * cos(a);
	d->ay = t->map[k][i] * d->step + (xx + zz) * d->step * sin(a);
	d->color_b = t->color[k + (k < t->map_rows - 1)][i];
	d->bx = (xx - (zz - 2)) * d->step * cos(a);
	d->by = t->map[k + (k < t->map_rows - 1)][i] * d->step \
		+ (xx + (zz - 2)) * d->step * sin(a);
	if (k < t->map_rows - 1)
		ft_xiaolinwu(d);
}

static void	ft_get_step(t_tr *t, t_dr *d)
{
	int		k;
	int		i;
	double	m;

	k = -1;
	while (++k < t->map_rows)
	{
		i = -1;
		while (++i < t->map_len)
		{
			m = t->map[k][i] + ((i - k) * 2 - t->map_len + t->map_rows) / 2;
			if ((!k && !i) || d->y_min > m)
				d->y_min = m;
			if ((!k && !i) || d->y_max < m)
				d->y_max = m;
		}
	}
	m = (d->wdth / 2 / (t->map_rows * (t->map_rows >= t->map_len) \
		+ t->map_len * (t->map_rows < t->map_len)));
	d->step = ((double)d->hght - 10) / 2 / d->y_max;
	d->step = d->step * (d->step <= m) + m * (d->step > m);
	if (d->y_min < 0)
		m = ((double)d->hght - 10) / 2 / (-d->y_min);
	d->step = d->step * (d->step <= m) + m * (d->step > m);
	d->step *= 0.95;
}

void	ft_draw_lines(t_tr *t, t_dr *d)
{
	int	k;
	int	i;

	ft_get_step(t, d);
	k = -1;
	while (++k < t->map_rows)
	{
		i = t->map_len;
		while (--i >= 0)
			ft_lines_ab_ac(k, i, t, d);
	}
}
