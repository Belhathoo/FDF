/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 22:15:05 by belhatho          #+#    #+#             */
/*   Updated: 2019/12/21 23:48:44 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			put_pixel(t_fdf *fdf, int x, int y, int color)
{
	if (x < 1000 && x >= 0 && y >= 0 && y < 1000)
		fdf->data[x + y * 1000] = color;
}

void			ft_background(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < 1000)
	{
		j = 0;
		while (j < 1000)
		{
			put_pixel(fdf, i, j, fdf->bcolor);
			j++;
		}
		i++;
	}
}

static void		ft_mlx_string(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 0, 0x555555 \
			, " FDF");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 490, 0, 0x111111, "1337");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 910, 0, 0xCCCCCC, "BELHATHO");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 12, 0x000000,
			" ----------------------------------------------------------\
			---------------------------------------");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 30, 0x1B4F72
	, "  PROJECTIONS        DEPLACEMENT           ZOOM");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 630, 30, 0x1B4F72,
	"ROTATION	                  Z-ATTITUDE");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 45, 0x2874A6\
		, "   P - O - I      8 - 4 - 2 - 6 - 5      (+) 0 (-)   \
			(left-right-up-down-pgUp-pgDwn)       (mouse)");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 80, 0x212F3D
			, "                BACKGROUND COLOR                             \
			GRAPH COLOR SHADING");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 95, 0x21618C
			, "   C(Cyprus)  V(White)  B(Black)  N(Orange)            \
			F(Grey)  G(Blue)  H(Red-Yellow) ");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 470, 1090, 0x555555, fdf->title);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 340, 1090, 0x444444\
					, "Title(Path): ");
}

void			side_win(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < 1000)
	{
		j = 0;
		while (j < 120)
		{
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, i, j, 0xD5D8DC);
			j++;
		}
		i++;
	}
	ft_mlx_string(fdf);
}
