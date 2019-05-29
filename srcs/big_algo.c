/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   big_algo.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/20 12:51:11 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/27 13:50:53 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		find_median_index_a(t_pile *piles)
{
	int half_pile_size;
	int current_smallest;

	half_pile_size = piles->size_a / 2 + piles->size_a % 2;
	while (half_pile_size)
	{
		current_smallest = find_smallest_in_a(piles);
		piles->p_a[current_smallest][MARKER] = USED;
		half_pile_size--;
	}
	return (current_smallest);
}

void	clean_markers(t_pile *piles)
{
	int cpt;

	if (piles->size_a != 0)
	{
		cpt = piles->size_a - 1;
		while (cpt >= 0)
		{
			piles->p_a[cpt][MARKER] = FULL;
			cpt--;
		}
	}
	if (piles->size_b != 0)
	{
		cpt = piles->size_b - 1;
		while (cpt >= 0)
		{
			piles->p_b[cpt][MARKER] = FULL;
			cpt--;
		}
	}
}
