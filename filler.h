/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:59:28 by mmpofu            #+#    #+#             */
/*   Updated: 2018/01/26 18:40:37 by mmpofu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     FILLER_H
# define    FILLER_H

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef	struct		s_valid
{
	int						x;
	int						y;
	int						n;
	struct s_valid			*next;
}					t_valid;

typedef struct      s_main
{
	t_valid				*head;
	int     			centerx;
    int     			centery;
	int					rightx;
	int					righty;
	int					toprightx;
	int					toprighty;
	int					vx;
	int					vy;
	char				player;
	char				enemy;
	char				**new_map;
	char				*line;
	int					fd;
	char				**split;
	int					x;
	int					y;
	char				**map;
	int					i;
	int					j;
	int					z;
	int		           	k;
	int					l;
	char	           	*save;
	char		       	**piece;
	int					enemy_p;
	int					my_p;
	int					enemy_p1;
	int					my_p1;	
}                      	t_main;

int						add_distance(t_valid **head, int n, int x, int y);
int         			topright(t_main *var);
int        				right(t_main *var);
int						middle(t_main *var);
int                     get_size(t_main *var);
int                     alloc_mem(t_main *var);
int                     save_map(t_main *var);
int						save_piece(t_main *var);
int						get_pcor(t_main *var);
int						search_valid(t_main *var);
int						add_moves(t_valid **head, int y, int x);

#endif
