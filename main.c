/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:33:19 by mmpofu            #+#    #+#             */
/*   Updated: 2018/01/31 13:30:09 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(void)
{
	t_main		var;

	get_size(&var);
	alloc_mem(&var);
	while (1)
	{
		save_map(&var);
		save_piece(&var);
		search_valid(&var);
		ft_putstr(ft_itoa(var.vy));
		ft_putstr(" ");
		ft_putstr(ft_itoa(var.vx));
		ft_putchar('\n');
	}
	return (0);
}
