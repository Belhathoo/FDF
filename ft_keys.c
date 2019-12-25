/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:52:33 by belhatho          #+#    #+#             */
/*   Updated: 2019/12/21 19:41:21 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		rotate(int key, t_fdf *fdf)
{
	if (key == 126)
		fdf->alpha -= 0.1;
	if (key == 125)
		fdf->alpha += 0.1;
	if (key == 123)
		fdf->beta -= 0.1;
	if (key == 124)
		fdf->beta += 0.1;
	if (key == 116)
		fdf->gamma += 0.1;
	if (key == 121)
		fdf->gamma -= 0.1;
	draw(fdf);
}

static void		move(int key, t_fdf *fdf)
{
	if (key == 86)
		fdf->x_offset -= 10;
	else if (key == 88)
		fdf->x_offset += 10;
	else if (key == 91)
		fdf->y_offset -= 10;
	else if (key == 87)
	{
		fdf->x_offset = 500 - (fdf->width / 2) * fdf->offset;
		fdf->y_offset = 500 - (fdf->height / 2) * fdf->offset;
	}
	else
		fdf->y_offset += 10;
	draw(fdf);
}

static void		zooming(int key, t_fdf *fdf)
{
	if (key == 69)
		fdf->zoom += 0.04;
	if (key == 78)
		fdf->zoom -= 0.04;
	if (key == 82)
	{
		fdf->z_zoom = 1;
		fdf->zoom = 1;
	}
	if (fdf->zoom < 0.01)
		fdf->zoom = 0.01;
	draw(fdf);
}

static void		recolor(int key, t_fdf *fdf)
{
	if (key == 9)
		fdf->bcolor = 0xFFFFFF;
	if (key == 11)
		fdf->bcolor = 0x000000;
	if (key == 8)
		fdf->bcolor = 0x003333;
	if (key == 45)
		fdf->bcolor = 0xFF9966;
	if (key == 3)
		fdf->gcolor = 0;
	if (key == 4)
		fdf->gcolor = 1;
	if (key == 5)
		fdf->gcolor = 2;
	draw(fdf);
}

int				key_pressed(int key, t_fdf *fdf)
{
	if (key == 53)
	{
		fdf_free(fdf);
		free(fdf);
		exit(0);
	}
	if (key == 123 || key == 124 || key == 125
			|| key == 126 || key == 121 || key == 116)
		rotate(key, fdf);
	if (key == 5 || key == 4 || key == 3 || key == 8
			|| key == 45 || key == 11 || key == 9)
		recolor(key, fdf);
	if (key == 84 || key == 86 || key == 91 || key == 88
			|| key == 87)
		move(key, fdf);
	if (key == 82 || key == 69 || key == 78)
		zooming(key, fdf);
	if (key == 34 || key == 35 || key == 31)
		projections(key, fdf);
	return (0);
}
