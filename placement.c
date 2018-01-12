/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:57:59 by mmpofu            #+#    #+#             */
/*   Updated: 2018/01/12 12:54:52 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			vaild_check(t_main *var)
{
	if (var->my_p == (var->my_p1 + 1))
		if (var->enemy_p == (var->enemy_p1 + 1))
			return (1);
	return (0);
}

int			p_count2(t_main *var)
{
	int     x;
    int     y;

    y = 0;
    var->enemy_p1 = 0;
    var->my_p1 = 0;
    while (y < var->y)
    {
		x = 0;
        while (x < var->x)
        {
            if (var->new_map[y][x] == 'X')
                var->enemy_p1++;
            if(var->new_map[y][x] == 'O')
                var->my_p1++;
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

	y = 0;
	var->enemy_p = 0;
	var->my_p = 0;
	while (y < var->y)
    {
		x = 0;
		while (x < var->x)
		{
		//	printf("%c", var->new_map[y][x]);
			/*if (var->new_map[y][x] == 'X')
				var->enemy_p++;
			if(var->new_map[y][x] == 'O')
			{
				var->my_p++;
				printf("%d", var->my_p1);
			}*/
        	x++;
		}
		y++;
    }
	return (0);
}

int			anew_map(t_main *var)
{
	int		x;

	if (!(var->new_map = (char**)malloc(sizeof(char*) * var->y + 1)))
		return (0);
	x = 0;
	while (x < var->x)
	{
		if (!(var->new_map[x] = (char*)malloc(sizeof(char) * var->x + 1)))
			return (0);
		x++;	
	}
	return (0);
}

int		check_valid(t_main var, int row, int col)
{
	int		x;
	int		y;

	anew_map(&var);
	y = 0;
	while (y < var.y)
	{
		x = 0;
		while (x < var.x)
		{
			var.new_map[y][x] = var.map[y][x];
			x++;
		}
		y++;
	}
	//p_count1(&var);
	y = 0;
	while (y < var.l)
	{
		x = 0;
		while (x < var.k)
		{
			if ((row + var.l <= var.y) && (col + var.k <= var.x))
			{
				if (var.piece[y][x] != '.')
				{
					var.new_map[row + y][col + x] = var.piece[y][x];
				}
			}
			else
				return (0);
			x++;
		}
		y++;
	}
	y = 0;

	var.enemy_p1 = 0;
	printf("%d\n", y);
	//p_count2(&var);
	while (y < var.y)
    {
        x = 0;
		var.enemy_p1 = 0;
        while (x < var.x)
        {

            if (var.new_map[y][x] == 'X')
                var.enemy_p1++;
            if(var.new_map[y][x] == 'O')
                var.my_p1++;
         	 printf("%d\n",  var.enemy_p1++);
            x++;
        }
		printf("\n");
        y++;
    }
	free(&(*var.new_map));	
	return (0);
}

int		search_valid(t_main var)
{
	int		x;
	int		y;

	y = 0;
	while (y < var.y)
	{
		x = 0;
		while (x < var.x)
		{
			check_valid(var, y, x);
			x++;
		}
		y++;
	}
	return (0);
}

int		get_pcor(t_main *var)
{

	var->i = 0;
	while (var->i < var->l)
	{
		var->j = 0;
		while(var->j < var->k)
		{
			if (var->piece[var->i][var->j] == '*')
			{
				//     printf("piece %d %d\n", var->i, var->j);
				// return (1);
			}
			var->j++;
		}
		var->i++;
	}
	return (0);
}
