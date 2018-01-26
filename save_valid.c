/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 10:53:20 by mmpofu            #+#    #+#             */
/*   Updated: 2018/01/26 10:32:45 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		add_moves(t_valid **head, int y, int x)
{
	t_valid		*temp;

	temp = (t_valid*)malloc(sizeof(t_valid));
	temp->y = y;
	temp->x = x;
	temp->next = (*head);
	(*head) = temp;
	return (0);
}

int		add_distance(t_valid **head, int n, int x, int y)
{
	t_valid		*temp;

	temp =(t_valid*)malloc(sizeof(t_valid));
	temp->x = x;
	temp->y = y;
	temp->n = n;
	temp->next = (*head);
	(*head) = temp;
	return (0);
}
