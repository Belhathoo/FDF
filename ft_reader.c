/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:56:34 by belhatho          #+#    #+#             */
/*   Updated: 2019/12/20 23:58:47 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_get_size_first_line(char *file)
{
	char	*line;
	char	**str;
	int		size;
	int		fd;

	size = 0;
	str = NULL;
	fd = open(file, O_RDONLY);
	if (get_next_line(fd, &line) > 0)
	{
		str = ft_strsplit(line, ' ');
		free(line);
		close(fd);
		size = ft_get_size_line(str);
		ft_cleanup(&str);
	}
	else
		close(fd);
	return (size);
}

void	ft_get_z_min_max(int ztab, t_fdf *fdf)
{
	if (ztab > fdf->zmax)
		fdf->zmax = ztab;
	if (ztab < fdf->zmin)
		fdf->zmin = ztab;
}

int		**ft_get_z(int fd, t_fdf *fdf)
{
	int		**ztab;
	char	**str;
	char	*line;
	int		i;
	int		j;

	i = 0;
	ztab = (int **)malloc(sizeof(int *) * (fdf->height + 1));
	while (get_next_line(fd, &line) > 0)
	{
		str = ft_strsplit(line, ' ');
		ztab[i] = (int *)malloc(sizeof(int) * fdf->width);
		j = 0;
		while (j < fdf->width)
		{
			ztab[i][j] = ft_atoi(str[j]);
			ft_get_z_min_max(ztab[i][j], fdf);
			j++;
		}
		i++;
		free(line);
		ft_cleanup(&str);
	}
	ztab[i] = NULL;
	return (ztab);
}
