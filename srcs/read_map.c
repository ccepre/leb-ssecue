#include "bsq.h"
void	read_map(char *path, t_map *map)
{
	int fd;
	char buf;
	int i;

	i = 0;
	if ((fd = open(path, O_RDONLY)) == -1)
		ft_puterr();;
	while (read(fd, &buf, 1) != 0 && buf != '\n')
	{}
	while (read(fd, &buf, 1) != 0)
	{
		map->nb_cases++;
		if (buf == '\n')
			map->nb_lines++;
	}
	if (!(map->map = malloc(sizeof(char) * map->nb_cases)))
		exit(1);
	map->nb_cases -= map->nb_lines;
	close(fd);
	fd = open(path, O_RDONLY);
	while (read(fd, &buf, 1) != 0 && buf != '\n')
	{}
	while (read(fd, &buf, 1) != 0)
		map->map[i++] = buf;
}
