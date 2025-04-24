/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:08:57 by famirant          #+#    #+#             */
/*   Updated: 2022/11/29 12:13:02 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Map error(1): Map must be rectangular
void	err1_rect(t_vars *vars)
{
	ft_printf("Error\n");
	ft_printf("MAP: Map must be rectangular\n");
	win_destroy(vars, 1);
}

// Map must be rectangular
void	check_map2(t_vars *vars, t_map *map)
{
	t_point	i;

	i.y = -1;
	while (++i.y < map->y)
	{
		i.x = -1;
		while (++i.x < map->x)
			if (!map->map[i.y][i.x])
				err1_rect(vars);
	}
	i.y = -1;
	while (++i.y < map->y)
		if (map->map[i.y][map->x + 1])
			err1_rect(vars);
}

// Map can be composed of only '0','1','C','E','P','N'
void	check_map_obj(t_vars *vars, char obj)
{
	if (!ft_char_in_array(obj, "01CEPN"))
	{
		ft_printf("Error\n");
		ft_printf("MAP: Map can be composed of only '0','1','C','E','P','N'\n");
		win_destroy(vars, 1);
	}
}

// Map can have 1 exit, 1+ collectible, 1 start && only composed of "01CEPN"
void	check_map1(t_vars *vars, t_map *map)
{
	int			xy[2];
	t_mapinfo	*info;

	info = &vars->map.info;
	if (info->exit != 1 || info->start != 1 || !info->collects)
	{
		ft_printf("Error\n");
		ft_printf("MAP: Map must contain 1 EXIT, \
AT LEAST 1 COLLECTIBLE, and 1 STARTING POSITION to be valid\n");
		win_destroy(vars, 1);
	}
	xy[1] = 0;
	while (xy[1] < map->y)
	{
		xy[0] = 0;
		while (xy[0] < map->x)
		{
			check_map_obj(vars, map->map[xy[1]][xy[0]]);
			xy[0]++;
		}
		xy[1]++;
	}
}

/* 3. Map
	• The map has to be constructed with 3 components:
		walls, collectibles, and free space.
	• The map can be composed of only these 5 characters:
		0 for an empty space,
		1 for a wall,
		C for a collectible,
		E for a map exit,
		P for the player’s starting position.
	• Other characters added for Bonus:
		N for enemies

		Here is a simple valid map:
			1111111111111
			10010000000C1
			1000011111001
			1P0011E000001
			1111111111111

	• The map must contain at least 1 exit, 1 collectible, and
		1 starting position.
		If the map contains a duplicates characters (exit/start), you should
		display an error message.
	• The map must be rectangular.
	• The map must be closed/surrounded by walls.
		If it’s not, the program must return an error.
	• You have to check if there’s a valid path in the map.
	• You must be able to parse any kind of map, as long as it respects
		the above rules.
	• Another example of a minimal .ber map:
		1111111111111111111111111111111111
		1E0000000000000C00000C000000000001
		1010010100100000101001000000010101
		1010010010101010001001000000010101
		1P0000000C00C0000000000000000000C1
		1111111111111111111111111111111111
	• If any misconfiguration of any kind is encountered in the file,
		the program must exit in a clean way, and return "Error\n" followed
		by an explicit error message of	your choice.
*/
void	check_map(t_vars *vars, t_map *map)
{
	t_point	i;
	int		*pos;

	check_map2(vars, map);
	check_map1(vars, map);
	check_map4(vars, map);
	pos = curr_entity_pos(map, 'P');
	i.x = pos[0];
	i.y = pos[1];
	free(pos);
	map->backup[i.y][i.x] = 'S';
	check_map3(vars, map, i);
	free_map_backup(map);
}
