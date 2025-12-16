/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_0_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:21:52 by rponomar          #+#    #+#             */
/*   Updated: 2024/11/05 23:09:03 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void	ft_set_drawer(t_dr *d)
{
	d->mlx = NULL;
	d->win = NULL;
	d->wdth = 2560;
	d->hght = 1440;
	d->img = NULL;
	d->addr = NULL;
	d->bpp = 0;
	d->line_len = 0;
	d->endian = 0;
}

static void	ft_set_tracker(t_tr *t, t_dr *d)
{
	t->d = d;
	t->map = NULL;
	t->map_len = 0;
	t->map_rows = 0;
	t->map_base = 0;
	t->color = NULL;
	t->color_min = 0xffffff;
	t->color_max = 0;
	t->color_dflt = 1;
}

static void	ft_check_arg(int argc, char *argv[])
{
	size_t	k;
	char	*file_ext;

	if (argc != 2)
		ft_error_message(1, NULL, NULL);
	k = ft_strlen(argv[1]);
	if (k < 5)
		ft_error_message(1, NULL, NULL);
	file_ext = argv[1];
	file_ext += (k - 4);
	if (ft_strncmp(file_ext, ".fdf", 4))
		ft_error_message(1, NULL, NULL);
}

static void	ft_start_fdf(t_tr *t, t_dr *d)
{
	d->mlx = mlx_init();
	if (!d->mlx)
		ft_error_message(8, t, d);
	d->win = mlx_new_window(d->mlx, d->wdth, d->hght, "Roman_Ponomarev_FDF");
	if (!d->win)
		ft_error_message(8, t, d);
	d->img = mlx_new_image(d->mlx, d->wdth, d->hght);
	d->addr = mlx_get_data_addr(d->img, &d->bpp, &d->line_len, &d->endian);
	if (!d->img || !d->addr)
		ft_error_message(8, t, d);
}

int	main(int argc, char *argv[])
{
	t_tr	t;
	t_dr	d;

	ft_check_arg(argc, argv);
	ft_set_drawer(&d);
	ft_set_tracker(&t, &d);
	ft_get_map(argv[1], &t);
	ft_start_fdf(&t, &d);
	ft_draw_image(&t, &d);
	return (0);
}
