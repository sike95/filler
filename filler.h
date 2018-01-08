
#ifndef     FILLER_H
# define    FILLER_H

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct      s_main
{
    char		*line;
	int		fd;
	char		**split;
	int		x;
	int		y;
	char		**map;
	int		i;
	int		j;
	int		z;
	int		           k;
	int		           l;
	char	           *save;
	char		       **piece;   
}                      t_main;

int                     get_size(t_main *var);
int                     alloc_mem(t_main *var);
int                     save_map(t_main *var);


#endif
