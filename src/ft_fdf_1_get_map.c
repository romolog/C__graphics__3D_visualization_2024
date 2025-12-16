/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_1_get_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:50:04 by rponomar          #+#    #+#             */
/*   Updated: 2025/01/23 16:07:41 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void	ft_parse_str(char *s, int *count, int k, t_tr *t)
{
	while (*s && *s != '\n')
	{
		while (*s && *s != '\n' && (*s == ' ' || (*s >= 9 && *s <= 13)))
			s++;
		if (*s && *s != '\n' && (*s == '-' || *s == '+'))
			s++;
		if (*s && *s != '\n' && *s >= '0' && *s <= '9')
			(*count)++;
		while (*s && *s != '\n' && *s >= '0' && *s <= '9')
			s++;
		if (*s && *s != '\n' && !ft_strncmp(s, ",0x", 3))
		{
			s += 3;
			k = 0;
			while (++k <= 8 && *s && *s != '\n' && ((*s >= '0' && *s <= '9') \
				|| (*s >= 'a' && *s <= 'f') || (*s >= 'A' && *s <= 'F')))
				s++;
		}
		if (*s && *s != '\n' && *s != ' ' && (*s < 9 || *s > 13))
			ft_error_message(7, t, NULL);
		while (*s && *s != '\n' && (*s == ' ' || (*s >= 9 && *s <= 13)))
			s++;
	}
}

static void	ft_check_row_len(char *s, t_tr *t)
{
	int		count;
	int		k;

	if (*s == '\n')
		ft_error_message(6, t, NULL);
	k = -1;
	count = 0;
	ft_parse_str(s, &count, k, t);
	if (!t->map_len)
		t->map_len = count;
	if (t->map_len != count)
		ft_error_message(6, t, NULL);
}

static void	ft_mem_arr(int *rows, t_tr *t)
{
	int			**temp_z;
	t_ll		**temp_color;
	int			m;

	if (*rows == __INT_MAX__)
		ft_error_message(5, t, NULL);
	(*rows) += (9 * (*rows)) * ((*rows) == ((*rows) * 10) / 10) \
		+ (__INT_MAX__ - *rows) * ((*rows) != ((*rows) * 10) / 10);
	temp_z = ft_calloc((*rows), sizeof(int *));
	temp_color = ft_calloc((*rows), sizeof(t_ll *));
	if (!temp_z || !temp_color)
		ft_error_message(5, t, NULL);
	m = -1;
	while (t->map && ++m < t->map_rows)
	{
		temp_z[m] = t->map[m];
		temp_color[m] = t->color[m];
	}
	if (t->color)
		free(t->color);
	t->color = temp_color;
	if (t->map)
		free(t->map);
	t->map = temp_z;
}

void	ft_get_map(char *file_name, t_tr *t)
{
	int		fd;
	char	*s;
	int		rows_mallocated;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_error_message(3, NULL, NULL);
	s = ft_get_next_line(fd);
	if (!s)
		ft_error_message(4, NULL, NULL);
	rows_mallocated = 10;
	while (s)
	{
		if (!t->map_rows || t->map_rows == rows_mallocated)
			ft_mem_arr(&rows_mallocated, t);
		ft_check_row_len(s, t);
		ft_put_row_to_map(s, t);
		t->map_rows++;
		free(s);
		s = ft_get_next_line(fd);
	}
	close(fd);
	while (rows_mallocated-- > t->map_rows)
		free(t->map[rows_mallocated]);
}
