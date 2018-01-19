/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:33:19 by mmpofu            #+#    #+#             */
/*   Updated: 2018/01/19 12:34:44 by mmpofu           ###   ########.fr       */
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
	int			fd;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	s = 0;
	fd = open("maap.txt", O_WRONLY | O_APPEND);
	while (1)
	{
		get_size(&var);
		alloc_mem(&var);
		save_map(&var);
		save_piece(&var);
//		printf("%c\n", var.map[0][0]);
//	y = 0;
	/*while (y < var.y)
    {
        x = 0;
        while (x < var.x)
        {
            printf("%c", var.map[y][x]);
    //      var->new_map[y][x] = var->map[y][x];
            x++;
        }
        printf("\n");
        y++;
    }*/
//	printf("\n");
//		get_pcor(&var);
		search_valid(&var);
//		ft_putendl("8 2");
		{
		ft_putstr_fd(ft_itoa(var.head->y), fd);
        ft_putstr_fd(" ", fd);
        ft_putstr_fd(ft_itoa(var.head->x), fd);
        ft_putstr_fd("\n", fd);
		}

//		if (var.head != NULL)
		{
		ft_putstr(ft_itoa(var.head->y));
		ft_putstr(" ");
		ft_putstr(ft_itoa(var.head->x));
		ft_putchar('\n');
		}
//		else
//			ft_putendl("0 0");
//		printf("%s %s\n", ft_itoa(var.head->y), ft_itoa(var.head->x));
		//	return (0);
        //	var.head = var.head->next;
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
	//	break ;
//		s++;
	}
	return (0);
}
