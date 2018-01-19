/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 10:53:20 by mmpofu            #+#    #+#             */
/*   Updated: 2018/01/16 11:23:29 by mmpofu           ###   ########.fr       */
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
