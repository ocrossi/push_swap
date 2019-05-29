/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_piles.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/27 15:08:47 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/27 15:51:11 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	free_piles(t_pile *piles)
{
	int cpt;

	cpt = 0;
	while (cpt < piles->size_a)
	{
		free(piles->p_a[cpt]);
		free(piles->p_b[cpt]);
		cpt++;
	}
	free(piles->p_a);
	free(piles->p_b);
}
