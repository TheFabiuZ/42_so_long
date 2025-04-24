/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:28:12 by famirant          #+#    #+#             */
/*   Updated: 2022/11/29 12:12:18 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Free map + backup
void	free_map_and_backup(t_map *map)
{
	while (map->y && map->map[--map->y] != NULL)
	{
		free(map->map[map->y]);
		free(map->backup[map->y]);
	}
	free(map->map);
	free(map->backup);
}

// Free map
void	free_map(t_map *map)
{
	while (map->y && map->map[--map->y] != NULL)
		free(map->map[map->y]);
	free(map->map);
}

// Free map
void	free_map_backup(t_map *map)
{
	int	y;

	y = map->y;
	while (y && map->backup[--y] != NULL)
		free(map->backup[y]);
	free(map->backup);
}
