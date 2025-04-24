/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:45:42 by famirant          #+#    #+#             */
/*   Updated: 2022/11/29 12:13:12 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Current collectibles not collected
int	curr_uncollected(t_map *map)
{
	int	collectibles;
	int	y;
	int	x;

	collectibles = 0;
	y = 1;
	while (y < map->y - 1)
	{
		x = 1;
		while (x < map->x - 1)
		{
			if (map->map[y][x] == 'C')
				collectibles++;
			x++;
		}
		y++;
	}
	return (collectibles);
}

// Entity move direction: | 0=Don't Move | 1=Up | 2=Left | 3=Down | 4=Right |
void	entity_move_direction(int movement, int *x, int *y)
{
	*x = 0;
	*y = 0;
	if (movement == 1)
		*y = -1;
	if (movement == 2)
		*x = -1;
	if (movement == 3)
		*y = 1;
	if (movement == 4)
		*x = 1;
}

// Entity movement
void	entity_movement(int movement, t_map	*map, t_vars *vars)
{
	char	pos;
	int		xy[2];
	int		*e_pos;

	if (movement == 0)
		return ;
	entity_move_direction(movement, &xy[0], &xy[1]);
	e_pos = curr_entity_pos(map, 'N');
	pos = map->map[e_pos[1] + xy[1]][e_pos[0] + xy[0]];
	if (pos == '1')
	{
		free(e_pos);
		return ;
	}
	if (pos == 'G')
		display_lose(vars->stats.uncollected, vars->map.info.collects, vars);
	map->map[e_pos[1] + xy[1]][e_pos[0] + xy[0]] = 'N';
	pos = map->backup[e_pos[1]][e_pos[0]];
	if (pos == 'N' || pos == 'G' || (pos == 'C' \
			&& vars->stats.uncollected == curr_uncollected(map)))
		map->map[e_pos[1]][e_pos[0]] = '0';
	else
		map->map[e_pos[1]][e_pos[0]] = pos;
	free(e_pos);
	my_map_to_window(vars, map);
}
