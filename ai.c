/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:39:00 by mmpofu            #+#    #+#             */
/*   Updated: 2018/01/31 12:39:46 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			ft_amend(t_main *var, t_valid *main, t_valid *temp)
{
	int		min;

	temp = main;
	min = main->n;
	while (temp)
	{
		if (temp->n < min)
			min = temp->n;
		temp = temp->next;
	}
	while (main)
	{
		if (min == main->n)
		{
			var->vy = main->y;
			var->vx = main->x;
		}
		main = main->next;
	}
	return (0);
}

int			center(t_main *var)
{
	int		n;
	t_valid *main;
	t_valid *temp;

	main = NULL;
	temp = NULL;
	temp = var->head;
	while (temp)
	{
		n = ((temp->y) - var->centery) + ((temp->x) - var->centerx);
		if (n < 0)
			n = n * -1;
		add_distance(&main, n, temp->x, temp->y);
		temp = temp->next;
	}
	ft_amend(var, main, temp);
	return (0);
}

int			topright(t_main *var)
{
	int		n;
	t_valid *main;
	t_valid *temp;

	main = NULL;
	temp = NULL;
	temp = var->head;
	while (temp)
	{
		n = ((temp->y) - var->toprighty) + ((temp->x) - var->toprightx);
		if (n < 0)
			n = n * (-1);
		add_distance(&main, n, temp->x, temp->y);
		temp = temp->next;
	}
	ft_amend(var, main, temp);
	return (0);
}

int			right(t_main *var)
{
	int		n;
	t_valid *main;
	t_valid	*temp;

	main = NULL;
	temp = NULL;
	temp = var->head;
	while (temp)
	{
		n = ((temp->y + var->l) - var->righty) +
			((temp->x + var->k) - var->rightx);
		if (n < 0)
			n = n * 1;
		add_distance(&main, n, temp->x, temp->y);
		temp = temp->next;
	}
	ft_amend(var, main, temp);
	return (0);
}

int			middle(t_main *var)
{
	int		n;
	t_valid *main;
	t_valid	*temp;

	main = NULL;
	temp = NULL;
	temp = var->head;
	while (temp)
	{
		n = ((temp->y + var->l) - var->bottomry) +
			((temp->x + var->k) - var->bottomrx);
		if (n < 0)
			n = n * -1;
		add_distance(&main, n, temp->x, temp->y);
		temp = temp->next;
	}
	ft_amend(var, main, temp);
	return (0);
}
