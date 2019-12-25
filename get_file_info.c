/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:27:52 by belhatho          #+#    #+#             */
/*   Updated: 2019/12/21 22:19:50 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			error_display(char *error)
{
	ft_putendl(error);
	return (0);
}

int			ft_get_size_line(char **str)
{
	int		size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

int			ft_get_nbr_lines(char *file, int size)
{
	char	*line;
	int		fd;
	int		nbr;
	char	**str;

	nbr = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		str = ft_strsplit(line, ' ');
		if (ft_get_size_line(str) < size)
		{
			error_display("Found wrong line length. Exiting.");
			close(fd);
			free(line);
			ft_cleanup(&str);
			return (-1);
		}
		nbr++;
		free(line);
		ft_cleanup(&str);
	}
	close(fd);
	return (nbr);
}

int			ft_cleanup(char ***tab)
{
	int		i;
	char	**str;

	str = *tab;
	i = 0;
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(str);
	return (0);
}
