#include "bsq.h"

t_map	*init_t_map()
{
	t_map	*init;

	if (!(init = malloc(sizeof(t_map))))
		exit(1);
	init->nb_cases = 0;
	init->nb_lines = 0;
	return (init);
}
