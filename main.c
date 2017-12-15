/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:33:19 by mmpofu            #+#    #+#             */
/*   Updated: 2017/12/15 09:52:17 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

int			main(int argc, char **argv)
{
	char	*line;
	int		fd;
	char	**split;
	int		x;
	int		y;
	char	**map;
	int		i;
	int		j;
	int		z;


	i = 0;
	j = 0;
	fd = open("map.txt", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (line[0] != '#')
		{
			//printf("%s\n", line);
		}
		if (ft_strstr(line, "Plateau"))
		{
			split = ft_strsplit(line, ' ');
			x = atoi(split[2]);
			y = atoi(split[1]);
		}
		
	}
	close(fd);

	if (!(map = (char**)malloc(sizeof(char*) * y + 1)))
		return (0);
	while (i < x)
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * y +  1)))
			return (0);
		i++;
	}

	fd = open("map.txt", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (ft_strchr(line, '.') && !ft_strchr(line, '#'))
		{
			z = 0;
			
			while (z < x + 3) // this will not work with big maps (Needs a fix)
			{
				if (!ft_isdigit(line[z]))
				{
				 printf("%c", line[z]);
				}
				 z++;
			}
			printf("\n");
		}
	}

	return (0);
}
