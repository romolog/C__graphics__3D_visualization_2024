/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_2_get_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:16:52 by rponomar          #+#    #+#             */
/*   Updated: 2024/11/05 21:40:19 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static int	ft_put_xyz(char **s, t_tr *t)
{
	t_ll		res;
	int			minus;
	int			is_num;

	is_num = 0;
	res = 0;
	minus = 1;
	while (**s == ' ' || (**s >= 9 && **s <= 13))
		(*s)++;
	minus -= (**s == '-') * 2;
	*s += (**s == '-' || **s == '+');
	is_num += (**s == '0');
	while (**s == '0')
		(*s)++;
	while (**s >= '0' && **s <= '9' && res <= (t_ll)(__INT_MAX__) + (minus < 0))
	{
		is_num = 1;
		res = res * 10 + ((**s) - '0');
		(*s)++;
	}
	if (!is_num || res > (t_ll)(__INT_MAX__) + (minus < 0) \
		|| (**s != ',' && **s != ' ' && (**s < 9 && **s > 13)))
		ft_error_message(6, t, NULL);
	return ((int)(res * minus));
}

static void	ft_hex_to_ll(char **s, long long *color, t_tr *t)
{
	int			k;
	int			r;
	char		*radix_low;
	char		*radix_up;
	int			is_num;

	is_num = 0;
	radix_low = "0123456789abcdef";
	radix_up = "0123456789ABSDEF";
	k = -1;
	while (++k < 8 && ((**s >= '0' && **s <= '9') \
		|| (**s >= 'a' && **s <= 'f') || (**s >= 'A' && **s <= 'F')))
	{
		is_num = 1;
		r = 0;
		while ((**s) != radix_low[r] && (**s) != radix_up[r])
			r++;
		*color = (*color) * 16 + r;
		(*s)++;
	}
	if (!is_num)
		ft_error_message(7, t, NULL);
}

static long long	ft_put_color(char **s, t_tr *t)
{
	t_ll		color;

	color = 0;
	if (*s && !ft_strncmp(*s, ",0x", 3))
		(*s) += 3;
	else if (!*s || !**s \
		|| **s == '\n' || **s == ' ' || (**s >= 9 && **s <= 13))
		return (-1);
	else
		ft_error_message(6, t, NULL);
	ft_hex_to_ll(s, &color, t);
	if (**s && **s != '\n' && **s != ' ' && (**s < 9 && **s > 13))
		ft_error_message(7, t, NULL);
	return (color);
}

void	ft_put_row_to_map(char *str, t_tr *t)
{
	int	k;

	t->map[t->map_rows] = ft_calloc(t->map_len, sizeof(int));
	t->color[t->map_rows] = ft_calloc(t->map_len, sizeof(t_ll));
	if (!t->map[t->map_rows] || !t->color[t->map_rows])
		ft_error_message(5, t, NULL);
	k = -1;
	while (++k < t->map_len)
	{
		t->map[t->map_rows][k] = ft_put_xyz(&str, t);
		t->color[t->map_rows][k] = ft_put_color(&str, t);
	}
}
