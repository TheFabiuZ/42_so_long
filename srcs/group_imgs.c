/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_imgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:27:57 by famirant          #+#    #+#             */
/*   Updated: 2022/11/29 12:14:01 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Create an img
void	group_imgs_img(t_vars *vars, t_img *i, char *t)
{
	int	*ll;

	ll = &(*i).line_length;
	(*i).img = mlx_xpm_file_to_image(vars->mlx, t, &(*i).width, &(*i).height);
	(*i).addr = mlx_get_data_addr((*i).img, &(*i).bpp, ll, &(*i).endian);
}

// Group images
void	group_imgs(t_vars *vars, t_grimgs *imgs)
{
	group_imgs_img(vars, &imgs->espace, vars->textures.espace);
	group_imgs_img(vars, &imgs->wall, vars->textures.wall);
	group_imgs_img(vars, &imgs->collectible, vars->textures.collectible);
	group_imgs_img(vars, &imgs->exit, vars->textures.exit);
	group_imgs_img(vars, &imgs->start, vars->textures.start);
	animations_imgs(vars, imgs);
	imgs->character = &imgs->acharacter.curr;
	imgs->enemy = &imgs->aenemy.curr;
}
