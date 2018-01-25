/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:33:19 by mmpofu            #+#    #+#             */
/*   Updated: 2018/01/25 14:55:42 by mmpofu           ###   ########.fr       */
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
	get_size(&var);
   	alloc_mem(&var);
	while (1)
	{
	//	get_size(&var);
	//	alloc_mem(&var);
		save_map(&var);
		save_piece(&var);
//	printf("\n");
//		get_pcor(&var);
		search_valid(&var);
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
		break ;
//		s++;
	}
	return (0);
}
