/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_8_xiaolinwu_plot.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:11:28 by rponomar          #+#    #+#             */
/*   Updated: 2024/11/08 17:43:04 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_plot(int x, int y, double bright, t_dr *d)
{
	uint32_t	color;
	uint32_t	a;
	uint32_t	b;
	double		k;
	uint32_t	*pxl_ptr;	

	a = (uint32_t)(d->color_a);
	b = (uint32_t)(d->color_b);
	if ((d->bxc - x) < 0.05 && (d->byc - x) < 0.05)
		k = 0.0;
	else
		k = sqrt(pow((d->bxc - x), 2.0) + pow((d->byc - y), 2.0)) \
			/ sqrt(pow((d->bxc - d->axc), 2.0) + pow((d->byc - d->ayc), 2.0));
	color = (uint32_t)((((double)(a << 8 >> 24)) * k \
		+ ((double)(b << 8 >> 24)) * (1 - k)) \
		* (bright + (1 - bright) / 2 * (bright > 0.05)));
	color = color * 0x100 + (uint32_t)((((double)(a << 16 >> 24)) * k \
		+ ((double)(b << 16 >> 24)) * (1 - k)) \
		* (bright + (1 - bright) / 2 * (bright > 0.05)));
	color = color * 0x100 + (uint32_t)((((double)(a << 24 >> 24)) * k \
		+ ((double)(b << 24 >> 24)) * (1 - k)) \
		* (bright + (1 - bright) / 2 * (bright > 0.05)));
	pxl_ptr = (uint32_t *)d->addr + (d->wdth / 2 + x) \
		+ (d->hght / 2 - y) * d->wdth;
	*pxl_ptr = color;
}
