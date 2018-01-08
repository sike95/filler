
#include "filler.h"

int     get_size(t_main *var)
{
    var->fd = open("map.txt", O_RDONLY);
	while (get_next_line(var->fd, &var->line))
	{
		if (var->line[0] != '#')
		{
			//printf("%s\n", line);
		}
		if (ft_strstr(var->line, "Plateau"))
		{
			var->split = ft_strsplit(var->line, ' ');
			var->x = atoi(var->split[2]);
			var->y = atoi(var->split[1]);
			free (var->split);
		}
		if (ft_strstr(var->line, "Piece"))
		{
			var->split = ft_strsplit(var->line, ' ');
			var->k = atoi(var->split[2]);
			var->l = atoi(var->split[1]);
			free (var->split);
		}
		
	}
	close(var->fd);
    return (0);
}

int     alloc_mem(t_main *var)
{

	if (!(var->map = (char**)malloc(sizeof(char*) * var->y + 1)))
		return (0);
	while (var->i < var->x)
	{
		if (!(var->map[var->i] = (char*)malloc(sizeof(char) * var->x +  1)))
			return (0);
		var->i++;
	}

	var->i = 0;
//	printf("%d\n", var->l);
	if (!(var->piece = (char**)malloc(sizeof(char*) * var->l + 1 )))
	return (0);
	while (var->i < var->k)
	{
		if (!(var->piece[var->i] = (char*)malloc(sizeof(char) * var->k + 1)))
		return (0);
		var->i++;
	}
    return (0);
}

int     save_map(t_main *var)
{
	int	z;

	z = 0;
    	var->z = 0;
	var->fd = open("map.txt", O_RDONLY);
	while (get_next_line(var->fd, &var->line))
	{
		if (ft_strchr(var->line, '.') && !ft_strchr(var->line, '#'))
		{
			if (var->save = ft_strchr(var->line, ' '))
			{
				var->save++;
				var->map[var->z] = var->save;
				var->z++;
			}
		}
		if (ft_strchr(var->line, '*'))
		{
			var->piece[z] = var->line;
//			printf("%s\n", var->piece[z]);
			z++;
			// printf("%s\n", var->line);
		}
	}
    close(var->fd);
    return (0);
}
