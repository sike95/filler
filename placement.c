/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:57:59 by mmpofu            #+#    #+#             */
/*   Updated: 2018/01/19 14:12:37 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			vaild_coordinates(t_main *var)
{
	//printf("%d %d\n", var->my_p, var->my_p1);
	if (var->my_p == (var->my_p1 + 1))
        if (var->enemy_p == (var->enemy_p1))
            return (1);
	return (0);
}

int			p_count(t_main *var)
{
	int     x;
    int     y;

	var->my_p = 0;
    var->enemy_p = 0;
	y = 0;
    while (y < var->y)
    {
        x = 0;
        while (x < var->x)
        {
            if (var->new_map[y][x] == 'O')
            {
                var->my_p++;
            }
            if (var->new_map[y][x] == 'X')
            {
                var->enemy_p++;
                //printf("%d\n", var->enemy_p);
            }
            x++;
        }
      //  printf("\n");
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
            if (var->new_map[y][x] == 'O')
            {
                var->my_p1++;
            }
            if (var->new_map[y][x] == 'X')
            {
                var->enemy_p1++;
                //printf("%d\n", var->enemy_p);
            }
            x++;
        }
      //  printf("\n");
        y++;
    }
	return (0);
}

int			anew_map(t_main *var)
{
	int		x;

	x = 0;
//	printf("x =%d %d\n", var->x, var->y);
	if (!(var->new_map = (char**)malloc(sizeof(char*) * var->y + 1)))
		return (0);
	while (x < var->x)
	{
		if (!(var->new_map[x] = (char*)malloc(sizeof(char) * var->x + 1)))
			return (0);
		x++;
		printf("%d\n", x);
	}
	printf("Hello\n");
	return (1);
}

int		check_valid(t_main *var, int row, int col)
{
	int		x;
	int		y;

//	anew_map(var);
	y = 0;
	while (y < var->y)
	{
		x = 0;
		while (x < var->x)
		{
	//		printf("%c", var->map[y][x]);
			var->new_map[y][x] = var->map[y][x];
//			printf("%c", var->new_map[y][x]);
			x++;
		}
//		printf("%d\n", y);
//		printf("\n");
		y++;
	}
	p_count(var);
	y = 0;
	while (y < var->l)
	{
		x = 0;
		while (x < var->k)
		{
			if ((row + var->l <= var->y) && (col + var->k <= var->x))
			{
				if (var->piece[y][x] != '.')
				{
					var->new_map[row + y][col + x] = var->piece[y][x];
				}
			}
			else
				return (0);
			x++;
		}
		y++;
	}
/*	y = 0;
    while (y < var->y)
    {
        x = 0;
        while (x < var->x)
        {
          printf("%c", var->new_map[y][x]);
            x++;
        }
      printf("\n");
        y++;
    }*/
	p_count1(var);
//	 printf("%d %d\n", var->my_p, var->my_p1);
	if (vaild_coordinates(var) == 1)
		return (1);
	return (0);
}

int		search_valid(t_main *var)
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
			{
			//printf("%d %d\n", y, x);
				add_moves(&var->head, y, x);

			}
			x++;
		}
		y++;
	}
	if (var->head == NULL)
	{
		ft_putendl("0 0");
		exit(1);
	}
	/*while (var->head != NULL)
	{
		printf("%s %s\n", ft_itoa(var->head->y), ft_itoa(var->head->x));
		exit (1);
		var->head = var->head->next;
	}*/
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
