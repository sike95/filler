/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 07:48:36 by mmpofu            #+#    #+#             */
/*   Updated: 2018/01/31 14:23:07 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_size(t_main *var)
{
	while (get_next_line(0, &var->line))
	{
		player_maps(var);
		if (ft_strstr(var->line, "super"))
			var->name = 'Y';
		if (ft_strstr(var->line, "Plateau"))
		{
			var->split = ft_strsplit(var->line, ' ');
			var->x = atoi(var->split[2]);
			var->y = atoi(var->split[1]);
			free(var->split[0]);
			free(var->split[1]);
			free(var->split[2]);
			break ;
		}
	}
	return (0);
}

int		alloc_mem(t_main *var)
{
	var->i = 0;
	if (!(var->map = (char**)malloc(sizeof(char*) * var->y + 1)))
		return (0);
	while (var->i < var->x)
	{
		if (!(var->map[var->i] = (char*)malloc(sizeof(char) * var->x + 1)))
			return (0);
		var->i++;
	}
	return (0);
}

int		save_map(t_main *var)
{
	var->z = 0;
	while (get_next_line(0, &var->line))
	{
		find_player(var);
		if (ft_strstr(var->line, "Piece"))
		{
			var->split = ft_strsplit(var->line, ' ');
			var->k = atoi(var->split[2]);
			var->l = atoi(var->split[1]);
			free(var->split[0]);
			free(var->split[1]);
			free(var->split[2]);
			break ;
		}
	}
	return (0);
}

int		save_piece(t_main *var)
{
	int		i;

	i = 0;
	var->z = 0;
	var->i = 0;
	if (!(var->piece = (char**)malloc(sizeof(char*) * var->l + 1)))
		return (0);
	while (var->i < var->k)
	{
		if (!(var->piece[var->i] = (char*)malloc(sizeof(char) * var->k + 1)))
			return (0);
		var->i++;
	}
	while (get_next_line(0, &var->line))
	{
		if (ft_strchr(var->line, '.') || ft_strchr(var->line, '*'))
		{
			var->piece[var->z] = var->line;
			var->z++;
		}
		i++;
		if (i == var->l)
			break ;
	}
	return (0);
}
