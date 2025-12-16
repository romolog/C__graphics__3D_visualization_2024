/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_3_draw_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:08:32 by rponomar          #+#    #+#             */
/*   Updated: 2024/11/05 21:40:36 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static int	ft_close_red_button(t_tr *t)
{
	ft_destroy_free(t, t->d);
	exit(EXIT_SUCCESS);
	return (0);
}

static int	ft_keyevent(int key, t_tr *t)
{
	if (key == FT_ESC_CODE)
	{
		ft_destroy_free(t, t->d);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

static void	ft_draw_background(t_dr *d)
{
	uint32_t	*p;
	int			k;

	p = (uint32_t *)d->addr;
	k = -1;
	while (++k < d->wdth * d->hght)
	{
		*p++ = 0x0f0f0f;
	}
}

static int	ft_render_img(t_dr *d)
{
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return (0);
}

void	ft_draw_image(t_tr *t, t_dr *d)
{
	long	event_mask;

	event_mask = 2047;
	ft_set_color(t);
	ft_draw_background(d);
	ft_draw_lines(t, d);
	mlx_loop_hook(d->mlx, &ft_render_img, d);
	mlx_key_hook(d->win, &ft_keyevent, t);
	mlx_hook(d->win, 17, event_mask, &ft_close_red_button, t);
	mlx_loop(d->mlx);
}
