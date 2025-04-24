/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:39:44 by famirant          #+#    #+#             */
/*   Updated: 2022/11/29 12:13:07 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Update the objects on map info
void	count_objects_add(t_map *map, char obj)
{
	if (obj == '0')
		map->info.espace++;
	if (obj == '1')
		map->info.wall++;
	if (obj == 'C')
		map->info.collects++;
	if (obj == 'E')
		map->info.exit++;
	if (obj == 'P')
		map->info.start++;
	if (obj == 'N')
		map->info.enemy++;
}

// Count map objects
void	count_objects(t_map *map)
{
	int	y;
	int	x;

	map->info.espace = 0;
	map->info.wall = 0;
	map->info.collects = 0;
	map->info.exit = 0;
	map->info.start = 0;
	map->info.enemy = 0;
	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			count_objects_add(map, map->map[y][x]);
			x++;
		}
		y++;
	}
}
