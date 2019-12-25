/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 00:48:57 by belhatho          #+#    #+#             */
/*   Updated: 2019/12/21 00:10:43 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ztab_free(t_fdf *fdf)
{
	int i;

	i = 0;
	while (i < fdf->height)
	{
		free(fdf->ztab[i]);
		i++;
	}
	free(fdf->ztab);
}

static void	free_all_pnts(t_fdf *fdf)
{
	int i;

	i = fdf->height - 1;
	while (i >= 0)
	{
		free(fdf->all_pnts[i]);
		i--;
	}
	free(fdf->all_pnts);
}

void		fdf_free(t_fdf *fdf)
{
	free_all_pnts(fdf);
	ztab_free(fdf);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	fdf->img_ptr = NULL;
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	fdf->win_ptr = NULL;
	fdf->mlx_ptr = NULL;
}
