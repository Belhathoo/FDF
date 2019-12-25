/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 20:09:13 by belhatho          #+#    #+#             */
/*   Updated: 2019/12/22 03:16:44 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			check_file(char *file)
{
	int		fd;
	char	buff[1];

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		error_display("NO data found !");
		close(fd);
		return (0);
	}
	if (fd > 4864 || fd < 0 || (read(fd, buff, 1) <= 0))
	{
		error_display("No Data Found !");
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

static int	initial(t_fdf *fdf, char **argv)
{
	fdf->width = ft_get_size_first_line(argv[1]);
	if ((fdf->height = ft_get_nbr_lines(argv[1], fdf->width)) == -1)
		return (-1);
	fdf->title = argv[1];
	fdf->zmax = -2147483648;
	fdf->zmin = 2147483647;
	return (1);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_fdf	*fdf;

	if (argc != 2)
	{
		error_display("usage: ./fdf file.fdf");
		return (0);
	}
	if (!check_file(argv[1]))
		return (0);
	fdf = (t_fdf*)malloc(sizeof(t_fdf));
	if (initial(fdf, argv) == -1)
	{
		free(fdf);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	fdf->ztab = ft_get_z(fd, fdf);
	close(fd);
	ft_putstr("HERE WE GO!!\n");
	ft_initial(fdf);
	draw(fdf);
	keys(fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
