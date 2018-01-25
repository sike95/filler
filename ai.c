/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:39:00 by mmpofu            #+#    #+#             */
/*   Updated: 2018/01/25 18:57:50 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			calculation(t_main *var)
{
	int		i;
	int		centerx;
	int		centery;
	int		n;
	t_valid	*temp;

	i = 0;
//	printf("%d\n", var->x/2);
//	printf("%d\n", var->y/2);

	centerx = var->x/2;
	centery = var->y/2;
	temp = var->head;
//	printf("%d\n", centery);
	while (temp)
    {
		
		n = ((temp->y + var->l) - centery) + ((temp->x + var->k) + var->k);
		printf("%d\n", n);
		//printf("%s %s\n", ft_itoa(temp->y), ft_itoa(temp->x));
        temp = temp->next;
    }
	return (0);
}
