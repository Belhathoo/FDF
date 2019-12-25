/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 22:30:26 by belhatho          #+#    #+#             */
/*   Updated: 2019/12/21 23:43:16 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		blanc_noir(int z, double percentage)
{
	if (z < 0)
		return (0xEEEEEE);
	if (z == 0)
		return (0xDDDDDD);
	if (percentage < 0.25)
		return (0xBBBBBB);
	if (percentage < 0.50)
		return (0xAAAAAA);
	if (percentage < 0.75)
		return (0x555555);
	if (percentage < 0.90)
		return (0x222222);
	return (0x111111);
}

static int		jaune_rouge(int z, double percentage)
{
	if (z < 0)
		return (0xFFFF66);
	if (z == 0)
		return (0xFFFF00);
	if (percentage < 0.25)
		return (0xFFCC00);
	if (percentage < 0.50)
		return (0xFF9900);
	if (percentage < 0.75)
		return (0xFF3300);
	if (percentage < 0.90)
		return (0xFF0000);
	return (0xCC0033);
}

static int		bleus(int z, double percentage)
{
	if (z < 0)
		return (0x00FFFF);
	if (z == 0)
		return (0x33CCFF);
	if (percentage < 0.25)
		return (0x0033FF);
	if (percentage < 0.50)
		return (0x0000FF);
	if (percentage < 0.75)
		return (0x0000CC);
	if (percentage < 0.90)
		return (0x000099);
	return (0X000033);
}

int				get_pnt_color(int z, t_fdf *fdf)
{
	double	percentage;

	percentage = percent(fdf->zmin, fdf->zmax, z);
	if (fdf->gcolor == 1)
		return (jaune_rouge(z, percentage));
	if (fdf->gcolor == 2)
		return (bleus(z, percentage));
	return (blanc_noir(z, percentage));
}
