/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_4_set_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:21:56 by rponomar          #+#    #+#             */
/*   Updated: 2024/11/08 15:57:04 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void	ft_minmax_alt(int *max, int *min, t_tr *t)
{
	int	k;
	int	i;

	k = -1;
	while (++k < t->map_rows)
	{
		i = -1;
		while (++i < t->map_len)
		{
			if ((!k && !i) || *max < t->map[k][i])
				*max = t->map[k][i];
			if ((!k && !i) || *min > t->map[k][i])
				*min = t->map[k][i];
		}
	}
}

static void	ft_put_dflt_color(t_tr *t)
{
	int	k;
	int	i;
	int	max;
	int	min;

	ft_minmax_alt(&max, &min, t);
	k = -1;
	while (++k < t->map_rows)
	{
		i = -1;
		while (++i < t->map_len)
		{
			if (max - min != 0)
			{
				t->color[k][i] = 0xff;
				t->color[k][i] = t->color[k][i] * 0x100 \
					+ 0xff * (max - t->map[k][i]) / (max - min);
				t->color[k][i] = t->color[k][i] * 0x100 \
					+ 0xff * (max - t->map[k][i]) / (max - min);
			}
			else
				t->color[k][i] = 0xdddddd;
		}
	}
}

void	ft_set_color(t_tr *t)
{
	int	k;
	int	i;

	k = -1;
	while (++k < t->map_rows)
	{
		i = -1;
		while (++i < t->map_len)
			t->color_dflt *= (t->color[k][i] == -1);
	}
	if (t->color_dflt)
	{
		ft_put_dflt_color(t);
		return ;
	}
	k = -1;
	while (++k < t->map_rows)
	{
		i = -1;
		while (++i < t->map_len)
		{
			if (t->color[k][i] == -1)
				t->color[k][i] = 0xddaa55;
		}
	}
}
