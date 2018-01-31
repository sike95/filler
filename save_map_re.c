/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map_re.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 12:53:28 by mmpofu            #+#    #+#             */
/*   Updated: 2018/01/31 14:22:03 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		player_maps(t_main *var)
{
	if (ft_strstr(var->line, "[./filler]"))
	{
		var->split = ft_strsplit(var->line, ' ');
		if (ft_strcmp(var->split[2], "p1") == 0)
		{
			var->player = 'O';
			var->enemy = 'X';
		}
		if (ft_strcmp(var->split[2], "p2") == 0)
		{
			var->player = 'X';
			var->enemy = 'O';
		}
	}
	return (0);
}

int		find_player(t_main *var)
{
	if ((ft_strchr(var->line, '.') ||
				ft_strchr(var->line, 'X') || ft_strchr(var->line, 'O')) &&
			!ft_strchr(var->line, '$'))
	{
		if ((var->save = ft_strchr(var->line, ' ')))
		{
			var->save++;
			var->map[var->z] = var->save;
			var->z++;
		}
	}
	return (0);
}
