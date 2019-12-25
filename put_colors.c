/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:05:28 by belhatho          #+#    #+#             */
/*   Updated: 2019/12/21 23:43:57 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double			percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int		get_shade(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int				get_color(t_pnt current, t_pnt start,\
		t_pnt end, t_pnt delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_shade((start.color >> 16) & 0xff,\
			(end.color >> 16) & 0xff, percentage);
	green = get_shade((start.color >> 8) & 0xff,\
			(end.color >> 8) & 0xff, percentage);
	blue = get_shade(start.color & 0xff, end.color & 0xff, percentage);
	return ((red << 16) | (green << 8) | blue);
}
