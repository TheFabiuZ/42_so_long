/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:59:21 by famirant          #+#    #+#             */
/*   Updated: 2022/11/29 12:13:59 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	go_left(char **tab, t_point size, t_point i, char c)
{
	if (i.x - 1 < size.x && i.x - 1 >= 0 && c != tab[i.y][i.x - 1] \
	&& 'F' != tab[i.y][i.x - 1])
	{
		i.x--;
		tab[i.y][i.x] = 'F';
		return (1);
	}
	return (0);
}

int	go_right(char **tab, t_point size, t_point i, char c)
{
	if (i.x + 1 < size.x && i.x + 1 >= 0 && c != tab[i.y][i.x + 1] \
	&& 'F' != tab[i.y][i.x + 1])
	{
		i.x++;
		tab[i.y][i.x] = 'F';
		return (1);
	}
	return (0);
}

int	go_down(char **tab, t_point size, t_point i, char c)
{
	if (i.y + 1 < size.y && i.y + 1 >= 0 && c != tab[i.y + 1][i.x] \
	&& 'F' != tab[i.y + 1][i.x])
	{
		i.y++;
		tab[i.y][i.x] = 'F';
		return (1);
	}
	return (0);
}

void	repeat(char **tab, t_point size, t_point i, char c)
{
	if (go_down(tab, size, i, c))
		repeat(tab, size, (t_point){i.x, i.y + 1}, c);
	if (go_left(tab, size, i, c))
		repeat(tab, size, (t_point){i.x - 1, i.y}, c);
	if (go_right(tab, size, i, c))
		repeat(tab, size, (t_point){i.x + 1, i.y}, c);
	if (i.y - 1 < size.y && i.y - 1 >= 0 && c != tab[i.y - 1][i.x] \
	&& 'F' != tab[i.y - 1][i.x])
	{
		tab[i.y - 1][i.x] = 'F';
		repeat(tab, size, (t_point){i.x, i.y - 1}, c);
	}
}

void	map_path(char **tab, t_point size, t_point begin)
{
	t_point	i;

	i.x = begin.x;
	i.y = begin.y;
	tab[i.y][i.x] = 'F';
	repeat(tab, size, i, '1');
}
