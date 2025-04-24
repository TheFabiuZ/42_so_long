/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_animgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:33:14 by famirant          #+#    #+#             */
/*   Updated: 2022/11/29 12:14:06 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Create a new animage
t_aimgs	*new_animage(t_vars *vars, t_animate *texture, int n)
{
	t_aimgs	*new;
	t_img	*i;
	char	*t;
	int		*ll;

	new = malloc(sizeof(t_aimgs));
	new->n = n;
	i = &new->curr;
	t = texture->next->curr;
	ll = &(*i).line_length;
	(*i).img = mlx_xpm_file_to_image(vars->mlx, t, &(*i).width, &(*i).height);
	(*i).addr = mlx_get_data_addr((*i).img, &(*i).bpp, ll, &(*i).endian);
	new->next = NULL;
	return (new);
}

// Total animages
void	ani_imgs_atot(t_aimgs *img, int i)
{
	i = img->n;
	img = img->next;
	while (img->n != i)
	{
		img->tot = i;
		img = img->next;
	}
}

// Add animages to the list
void	ani_imgs_a(t_vars *vars, t_animate *temp, t_aimgs *img)
{
	t_aimgs	*first_node;
	int		i;

	first_node = img;
	i = 1;
	while (temp->next)
	{
		img->next = new_animage(vars, temp, i++);
		img = img->next;
		temp = temp->next;
	}
	img->next = first_node;
	img->tot = i;
	ani_imgs_atot(img, i);
}

// Animations images
void	animations_imgs(t_vars *vars, t_grimgs *imgs)
{
	t_animate	*temp;
	t_aimgs		*img;

	group_imgs_img(vars, &imgs->acharacter.curr, vars->textures.character.curr);
	imgs->acharacter.n = 0;
	temp = &vars->textures.character;
	img = &imgs->acharacter;
	ani_imgs_a(vars, temp, img);
	group_imgs_img(vars, &imgs->aenemy.curr, vars->textures.enemy.curr);
	imgs->aenemy.n = 0;
	temp = &vars->textures.enemy;
	img = &imgs->aenemy;
	ani_imgs_a(vars, temp, img);
}
