/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initial.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 00:00:37 by belhatho          #+#    #+#             */
/*   Updated: 2019/12/21 19:38:33 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			mlx_initial(t_fdf *fdf)
{
	fdf->offset = 700 / fdf->width;
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 1120, fdf->title);
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, 1000, 1000);
	fdf->data = (int *)mlx_get_data_addr(fdf->img_ptr, &(fdf->bpp),\
			&(fdf->line), &(fdf->endian));
	fdf->x_offset = 500 - (fdf->width / 2) * fdf->offset;
	fdf->y_offset = 500 - (fdf->height / 2) * fdf->offset;
	fdf->zoom = 1;
	fdf->z_zoom = 1;
	fdf->bcolor = 0x003333;
	fdf->gcolor = 0;
	fdf->alpha = 0;
	fdf->gamma = 0;
	fdf->beta = 0;
}

void				ft_initial(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	mlx_initial(fdf);
	fdf->all_pnts = (t_pnt **)malloc(sizeof(t_pnt *) * (fdf->height + 1));
	while (i < fdf->height)
	{
		fdf->all_pnts[i] = (t_pnt *)malloc(sizeof(t_pnt) * fdf->width);
		j = 0;
		while (j < fdf->width)
		{
			fdf->all_pnts[i][j].x = j * fdf->offset
				- ((fdf->width / 2) * fdf->offset);
			fdf->all_pnts[i][j].y = i * fdf->offset
				- ((fdf->height / 2) * fdf->offset);
			fdf->all_pnts[i][j].color = fdf->ztab[i][j];
			j++;
		}
		i++;
	}
	fdf->all_pnts[i] = NULL;
}
