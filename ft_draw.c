/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 00:12:29 by belhatho          #+#    #+#             */
/*   Updated: 2019/12/21 00:16:16 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int						get_line_color(t_pnt start, t_pnt end)
{
	if (start.color > end.color)
		return (start.color + 0xffffff);
	else
		return (end.color + 0x000000);
}

static void				draw_line(t_pnt a, t_pnt b, t_fdf *fdf)
{
	fdf->delta.x = b.x > a.x ? (b.x - a.x) : (a.x - b.x);
	fdf->delta.y = b.y > a.y ? (b.y - a.y) : (a.y - b.y);
	fdf->sign.x = a.x < b.x ? 1 : -1;
	fdf->sign.y = a.y < b.y ? 1 : -1;
	fdf->e_a = 0;
	fdf->e_b = 0;
	fdf->cur = a;
	while (fdf->cur.x != b.x || fdf->cur.y != b.y)
	{
		put_pixel(fdf, fdf->cur.x, fdf->cur.y,
				get_color(fdf->cur, a, b, fdf->delta));
		fdf->e_a += fdf->delta.y;
		fdf->e_b += fdf->delta.x;
		if (2 * fdf->e_a >= fdf->delta.x)
		{
			fdf->e_a -= fdf->delta.x;
			fdf->cur.y += fdf->sign.y;
		}
		if (2 * fdf->e_b >= fdf->delta.y)
		{
			fdf->e_b -= fdf->delta.y;
			fdf->cur.x += fdf->sign.x;
		}
	}
}

t_pnt					project(int i, int j, t_fdf *fdf)
{
	t_pnt	new;
	int		z;
	int		previous_x;
	int		previous_y;

	z = fdf->ztab[i][j] * fdf->z_zoom;
	new.color = get_pnt_color(fdf->all_pnts[i][j].color, fdf);
	new.y = fdf->all_pnts[i][j].y * cos(fdf->alpha) + z * sin(fdf->alpha);
	z = -fdf->all_pnts[i][j].y * sin(fdf->alpha) + z * cos(fdf->alpha);
	new.x = fdf->all_pnts[i][j].x * cos(fdf->beta) + z * sin(fdf->beta);
	previous_x = new.x;
	previous_y = new.y;
	new.x = previous_x * cos(fdf->gamma) - previous_y * sin(fdf->gamma);
	new.y = previous_x * sin(fdf->gamma) + previous_y * cos(fdf->gamma);
	new.x = new.x * fdf->zoom + (fdf->width / 2) * fdf->offset + fdf->x_offset;
	new.y = new.y * fdf->zoom + (fdf->height / 2) * fdf->offset + fdf->y_offset;
	return (new);
}

void					draw(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_background(fdf);
	if (fdf->width == 1 && fdf->height == 1)
		put_pixel(fdf, 500, 500, 0x222222);
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			if (j != fdf->width - 1)
				draw_line(project(i, j, fdf), project(i, j + 1, fdf), fdf);
			if (i != fdf->height - 1)
				draw_line(project(i, j, fdf), project(i + 1, j, fdf), fdf);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 120);
	side_win(fdf);
}
