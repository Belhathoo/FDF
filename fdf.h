/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:26:10 by belhatho          #+#    #+#             */
/*   Updated: 2019/12/22 00:43:58 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include <mlx.h>
# include <math.h>

typedef struct		s_pnt
{
	int				x;
	int				y;
	int				color;
}					t_pnt;

typedef struct		s_fdf
{
	int				**ztab;
	int				zmin;
	int				zmax;

	t_pnt			**all_pnts;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*title;

	int				*data;
	int				bpp;
	int				endian;
	int				line;

	int				height;
	int				width;
	int				offset;

	t_pnt			delta;
	t_pnt			sign;
	t_pnt			cur;
	int				e_a;
	int				e_b;

	double			alpha;
	double			beta;
	double			gamma;
	float			z_zoom;
	float			zoom;
	int				x_offset;
	int				y_offset;

	int				bcolor;
	int				gcolor;
}					t_fdf;

int					ft_get_size_line(char **str);
int					ft_get_nbr_lines(char *file, int size);

int					ft_get_size_first_line(char *file);
int					**ft_get_z(int fd, t_fdf *fdf);
void				ft_get_z_min_max(int ztab, t_fdf *fdf);

void				ft_initial(t_fdf *fdf);
int					ft_cleanup(char ***tab);

void				side_win(t_fdf *fdf);
void				ft_background(t_fdf *fdf);
void				put_pixel(t_fdf *fdf, int x, int y, int color);

void				draw(t_fdf *fdf);
t_pnt				project(int i, int j, t_fdf *fdf);

int					get_pnt_color(int z, t_fdf *fdf);
int					get_color(t_pnt current, t_pnt start,\
						t_pnt end, t_pnt delta);
double				percent(int start, int end, int current);

void				projections(int key, t_fdf *fdf);
void				keys(t_fdf *fdf);
int					key_pressed(int key, t_fdf *fdf);

int					error_display(char *error);

void				fdf_free(t_fdf *fdf);

#endif
