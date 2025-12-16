/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_9_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:28:17 by rponomar          #+#    #+#             */
/*   Updated: 2024/12/03 12:36:30 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_destroy_free(t_tr *t, t_dr *d)
{
	int	rows;

	if (t && t->map)
	{
		rows = t->map_rows;
		while (t->map_rows-- > 0)
			free(t->map[t->map_rows]);
		free(t->map);
	}
	if (t && t->color)
	{
		while (rows-- > 0)
			free(t->color[rows]);
		free(t->color);
	}
	if (d && d->img)
		mlx_destroy_image(d->mlx, d->img);
	if (d && d->win)
		mlx_destroy_window(d->mlx, d->win);
	if (d && d->mlx)
		mlx_destroy_display(d->mlx);
	if (d && d->mlx)
		free(d->mlx);
}

void	ft_error_message(int n, t_tr *t, t_dr *d)
{
	if (n == 1)
		perror("Error: invalid arg, should be 1 map file *.fdf\nErrno");
	else if (n == 2)
		perror("Error: failed to init mlx\nErrno");
	else if (n == 3)
		perror("Error: failed to open the map\nErrno");
	else if (n == 4)
		perror("Error: invalid map or can't be read\nErrno");
	else if (n == 5)
		perror("Error: map failure malloc\nErrno");
	else if (n == 6)
		perror("Error: invalid arg or different line length in map\nErrno");
	else if (n == 7)
		perror("Error: invalid color\nErrno");
	else if (n == 8)
		perror("Error: failed to run some minlibx func\nErrno");
	ft_destroy_free(t, d);
	exit(EXIT_FAILURE);
}

// void	ft_print_2d(t_tr *t)
// {
// 	int	row;
// 	int	len;
//
// 	row = -1;
// 	ft_printf("\n\n			__START OF MAP\n");
// 	while (++row < t->map_rows)
// 	{
// 		len = -1;
// 		while (++len < t->map_len)
// 			ft_printf("% 4d ", t->map[row][len]);
// 		ft_printf("\n\n");
// 	}
// 	ft_printf("\n\n		10 = %d \n", t->map[2][2]);
// 	ft_printf("			END OF MAP\n\n");
// 	// ft_printf("\n\n			START OF COLOR\n");
// 	// row = -1;
// 	// while (++row < t->map_rows)
// 	// {
// 	// 	len = -1;
// 	// 	while (++len < t->map_len)
// 	// 		printf("%#llx ", t->color[row][len]);
// 	// 	ft_printf("\n\n");
// 	// }
// 	// ft_printf("\n\n		-1 = %d \n", t->color[2][2]);
// 	// ft_printf("			_END OF MAP\n\n");
// }
