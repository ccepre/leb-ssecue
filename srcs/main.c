#include "bsq.h"

int		check_line(t_bsq *bsq, t_map *map, t_fl *fl, int p)
{
	int i;

	i = 0;
	while ((i < bsq->siz ) && ( map->map[p] != '\n') &&
			((p - bsq->siz) < map->nboct))
	{
		if (map->map[p] == fl->obs)
			return(1);
		p++;
		i++;
	}
	return(0);
}
void	check_sq(t_bsq *bsq, t_map *map, t_fl *fl)
{
	int p;
	int lines;

	while (bsq->siz <= map->map_x)
	{
	lines = 0;
		while (lines < bsq->siz)
		{
			p = bsq->pos + ((map->map_x + 1) * lines);
			if (check_line(bsq, map, fl, p) == 1)
				return;
			lines++;
		}
		bsq->siz++;
	}
}

int		main(int ac, char **av)
{
	t_fl *fl;
	t_map *map;
	t_bsq *bsq;

	fl = init_t_fl();
	map = init_t_map();
	bsq = init_t_bsq();
	if (ac != 2)
		return (0);
	read_fl(av[1], fl);
	read_map(av[1], map);
	check_map(fl, map);
	printf("x: %d, y: %d\n", map->map_x, map->map_y);
	check_sq(bsq, map, fl);
	printf("siz :%d, pos: %d\n", bsq->siz - 1, bsq->pos);

	ft_putstr(map->map);
	return (0);
}
