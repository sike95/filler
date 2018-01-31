/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resources.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:42:43 by mmpofu            #+#    #+#             */
/*   Updated: 2018/01/31 14:25:23 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			vaild_coordinates(t_main *var)
{
	if (var->my_p == (var->my_p1 + 1))
		if (var->enemy_p == (var->enemy_p1))
			return (1);
	return (0);
}

int			p_count(t_main *var)
{
	int		x;
	int		y;

	var->my_p = 0;
	var->enemy_p = 0;
	y = 0;
	while (y < var->y)
	{
		x = 0;
		while (x < var->x)
		{
			if (var->new_map[y][x] == var->player)
				var->my_p++;
			if (var->new_map[y][x] == var->enemy)
				var->enemy_p++;
			x++;
		}
		y++;
	}
	return (0);
}

int			p_count1(t_main *var)
{
	int		x;
	int		y;

	var->my_p1 = 0;
	var->enemy_p1 = 0;
	y = 0;
	while (y < var->y)
	{
		x = 0;
		while (x < var->x)
		{
			if (var->new_map[y][x] == var->player)
				var->my_p1++;
			if (var->new_map[y][x] == var->enemy)
				var->enemy_p1++;
			x++;
		}
		y++;
	}
	return (0);
}

int			anew_map(t_main *var)
{
	int		x;

	x = 0;
	if (!(var->new_map = (char**)malloc(sizeof(char*) * var->y + 1)))
		return (0);
	while (x < var->x + 1)
	{
		if (!(var->new_map[x] = (char*)malloc(sizeof(char) * var->x + 1)))
			return (0);
		x++;
	}
	return (1);
}
