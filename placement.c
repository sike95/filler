/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:57:59 by mmpofu            #+#    #+#             */
/*   Updated: 2018/01/31 14:23:19 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			check_valid2(t_main *var, int row, int col)
{
	int		x;
	int		y;

	y = 0;
	while (y < var->l)
	{
		x = 0;
		while (x < var->k)
		{
			if ((row + var->l <= var->y) && (col + var->k <= var->x))
			{
				if (var->piece[y][x] != '.')
					var->new_map[row + y][col + x] = var->piece[y][x];
			}
			else
				return (0);
			x++;
		}
		y++;
	}
	return (0);
}

int			check_valid(t_main *var, int row, int col)
{
	int		x;
	int		y;

	y = 0;
	while (y < var->y)
	{
		x = 0;
		while (x < var->x)
		{
			var->new_map[y][x] = var->map[y][x];
			x++;
		}
		y++;
	}
	p_count(var);
	check_valid2(var, row, col);
	p_count1(var);
	if (vaild_coordinates(var) == 1)
		return (1);
	return (0);
}

int			search2(t_main *var)
{
	var->centerx = var->x / 2;
	var->centery = var->y / 2;
	var->bottomrx = var->x - 1;
	var->bottomry = var->y - 1;
	var->rightx = 0;
	var->righty = 0;
	var->toprightx = var->x - 1;
	var->toprighty = 0;
	if (var->x == 17 && var->player == 'O')
		middle(var);
	else if (var->map[var->righty][var->rightx] == '.')
		right(var);
	else if (var->map[var->bottomry][var->bottomrx] == '.')
		middle(var);
	else if (var->map[var->toprighty][var->toprightx] == '.')
		topright(var);
	else
		center(var);
	return (0);
}

int			search_valid(t_main *var)
{
	int		x;
	int		y;

	anew_map(var);
	y = 0;
	var->head = NULL;
	while (y < var->y)
	{
		x = 0;
		while (x < var->x)
		{
			if (check_valid(var, y, x) == 1)
				add_moves(&var->head, y, x);
			x++;
		}
		y++;
	}
	if (var->head == NULL)
	{
		ft_putendl("0 0");
		exit(1);
	}
	search2(var);
	return (0);
}
