/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:10:17 by famirant          #+#    #+#             */
/*   Updated: 2022/11/29 12:13:39 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Generate a random number
int	randint(int next)
{
	next = next * 1103515245 + 12345;
	return ((unsigned int)(next / 65536) % 32768);
}

// Change current asset animation
void	change_animation(int *an, t_aimgs *img, t_img **curr_img)
{
	if (*an < 0 || *an > img->tot)
		*an = 0;
	while (img->n != *an)
		img = img->next;
	*curr_img = &img->curr;
}

// Render frame, change animations, move enemy
int	render_frame(t_vars *vars)
{
	static int	millisecond;
	static int	seed;
	static int	animation[2];
	t_grimgs	*t;

	if (!vars->win)
		return (1);
	if (millisecond == 9000)
	{
		t = &vars->grimgs;
		animation[0]++;
		animation[1]++;
		change_animation(&animation[0], &t->acharacter, &t->character);
		change_animation(&animation[1], &t->aenemy, &t->enemy);
		millisecond = 0;
	}
	if (seed % 90000 == 0 && vars->map.info.enemy > 0)
		entity_movement(randint(seed) % 5, &vars->map, vars);
	else if (millisecond % 9000 == 0)
		my_map_to_window(vars, &vars->map);
	if (seed > 2000000)
		seed = 1;
	seed++;
	millisecond++;
	return (0);
}
