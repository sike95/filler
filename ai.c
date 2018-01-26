/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:39:00 by mmpofu            #+#    #+#             */
/*   Updated: 2018/01/26 18:34:30 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			topright(t_main *var)
{
	 int     min;
    int     i;
    int     n;
    t_valid *main;
    t_valid *temp;

    i = 0;
    main = NULL;
    temp = NULL;
    temp = var->head;
        while (temp)
    {
        n = ((temp->y + var->l) - var->toprighty) + ((temp->x + var->k) - var->toprightx);
        if (n < 0)
            n = n * -1;
        add_distance(&main, n, temp->x, temp->y);
//      printf("%d\n", n);
    //  printf("%s %s\n", ft_itoa(temp->y), ft_itoa(temp->x));
        temp = temp->next;
    }
    temp = main;
    min = main->n;
    while (temp)
    {
        if (temp->n < min)
        {
            min = temp->n;
    //      printf("%d\n", min);
        }
//      printf("%s %s %d\n", ft_itoa(temp->y), ft_itoa(temp->x), main->n);
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

int			right(t_main *var)
{
	int		min;
	int		i;
	int		n;
	t_valid *main;
	t_valid	*temp;

	i = 0;
	main = NULL;
	temp = NULL;
	temp = var->head;
	    while (temp)
    {
        n = ((temp->y + var->l) - var->righty) + ((temp->x + var->k) - var->rightx);
        if (n < 0)
            n = n * -1;
        add_distance(&main, n, temp->x, temp->y);
//      printf("%d\n", n);
    //  printf("%s %s\n", ft_itoa(temp->y), ft_itoa(temp->x));
        temp = temp->next;
    }
    temp = main;
    min = main->n;
    while (temp)
    {
        if (temp->n < min)
        {
            min = temp->n;
    //      printf("%d\n", min);
        }
//      printf("%s %s %d\n", ft_itoa(temp->y), ft_itoa(temp->x), main->n);
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

int			middle(t_main *var)
{
	int		i;
	int		n;
	int		min;
	t_valid *main;
	t_valid	*temp;

	i = 0;
	main = NULL;
	temp = NULL;
//	printf("%d\n", var->x/2);
//	printf("%d\n", var->y/2);

	temp = var->head;
//	printf("%d %d\n", var->centery, var->centerx);
	while (temp)
    {
		n = ((temp->y + var->l) - var->centery) + ((temp->x + var->k) - var->centerx);
		if (n < 0)
			n = n * -1;
		add_distance(&main, n, temp->x, temp->y);
//		printf("%d\n", n);
	//	printf("%s %s\n", ft_itoa(temp->y), ft_itoa(temp->x));
        temp = temp->next;
    }
	temp = main;
	min = main->n;
	while (temp)
	{
		if (temp->n < min)
		{
			min = temp->n;
	//		printf("%d\n", min);
		}
//		printf("%s %s %d\n", ft_itoa(temp->y), ft_itoa(temp->x), main->n);
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
