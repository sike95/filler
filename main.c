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

#include "filler.h"

int			main(int argc, char **argv)
{
	t_main		var;
	int			i;
	int			j;

	i = 0;
	j = 0;
	var.i = 0;
	var.j = 0;
	get_size(&var);
	alloc_mem(&var);
	save_map(&var);
	
	while (j < var.y)
	{
		i = 0;
		while (i < var.x)
		{
			//if (var.map[j][i] == 'O')
			{
				printf("%c", var.map[j][i]);
			}
			i++;
		}
		printf("\n");
		j++;
	}

	j = 0;
	while (j < var.l)
	{
		i = 0;
		while (i < var.k)
		{
			printf("%c", var.piece[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
	return (0);
}
