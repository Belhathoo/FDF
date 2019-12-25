/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:43:34 by belhatho          #+#    #+#             */
/*   Updated: 2019/12/21 19:43:45 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			projections(int key, t_fdf *fdf)
{
	if (key == 34)
	{
		fdf->alpha = -0.955316618;
		fdf->gamma = 0.45;
		fdf->beta = -0.615479709;
	}
	if (key == 35)
	{
		fdf->alpha = 0;
		fdf->gamma = 0;
		fdf->beta = 0;
	}
	if (key == 31)
		fdf->gamma += 0.785398;
	draw(fdf);
}

int				ft_mouse_press(int button, int x, int y, t_fdf *fdf)
{
	x = y;
	if (button == 5)
		fdf->z_zoom += 1;
	else if (button == 4)
		fdf->z_zoom -= 1;
	if (fdf->z_zoom < 0.01)
		fdf->z_zoom = 0;
	draw(fdf);
	return (button);
}

void			keys(t_fdf *fdf)
{
	mlx_hook(fdf->win_ptr, 2, 0, key_pressed, fdf);
	mlx_hook(fdf->win_ptr, 4, 0, ft_mouse_press, fdf);
}
