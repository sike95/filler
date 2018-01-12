/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:33:19 by mmpofu            #+#    #+#             */
/*   Updated: 2018/01/11 18:23:27 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(void)
{
	t_main		var;
	int			i;
	int			j;
	int			x;
	int			y;
	int			s;
	//char		*place;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	s = 0;
//	while (s < 10)
	{
		get_size(&var);
		alloc_mem(&var);
		save_map(&var);
		save_piece(&var);
		get_pcor(&var);
		search_valid(var);
//		printf("%d %d\n", var.i, var.j);
	/*	while (y < var.y)
		{
			x = 0;
			while (x < var.x)
			{
				if (var.map[y][x] == 'O' && var.map[y][x + 1] == '.')
				{
				//	printf("%d %d\n", var.i, var.j);
					place = ft_strjoin(ft_strcat(ft_itoa(y - var.i), " "), 
							ft_itoa(x - var.j));
				}
				x++;
			}
			y++;
		}*/
		//ft_putendl(place);
		//printf("%s\n", place);
//		s++;
	}
	return (0);
}
