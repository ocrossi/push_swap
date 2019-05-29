/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ba2.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/22 16:32:31 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 13:12:25 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		divide_and_conquer(t_pile *piles)
{
	int median;
	int cpt;

	cpt = piles->size_a - 1;
	median = piles->p_a[find_median_index_a(piles)][DATA];
	while (cpt >= 0)
	{
		if (piles->p_a[piles->size_a - 1][DATA] <= median)
			all_ops("pb", piles, 1);
		all_ops("rra", piles, 1);
		cpt--;
	}
	piles->p_b[piles->size_b - 1][MARKER] = USED;
	return (0);
}

int		counter_b(t_pile *piles)
{
	int cpt;
	int ret;

	if (piles->size_b < 1)
		return (0);
	cpt = piles->size_b - 1;
	ret = 0;
	if (piles->p_b[piles->size_b - 1][MARKER] == USED)
		piles->p_b[piles->size_b - 1][MARKER] = FULL;
	while (cpt)
	{
		if (piles->p_b[cpt][MARKER] == USED)
			break ;
		cpt--;
		ret++;
	}
	return (ret);
}

void	push_on_half_median(t_pile *piles, int nb)
{
	int cpt;

	cpt = 0;
	piles->p_a[piles->size_a - 1][MARKER] = USED;
	while (nb > 0)
	{
		if (piles->p_b[piles->size_b - 1][MARKER] == TO_PUSH)
		{
			all_ops("pa", piles, 1);
			nb--;
		}
		else
		{
			all_ops("rb", piles, 1);
			cpt++;
		}
	}
	while (cpt)
	{
		all_ops("rrb", piles, 1);
		cpt--;
	}
	piles->p_b[piles->size_b - 1][MARKER] = USED;
}

void	divide_b_effect(t_pile *piles)
{
	int nb;
	int cpt;
	int bindex;

	nb = 0;
	cpt = counter_b(piles);
	while (cpt / 2)
	{
		bindex = find_bigest_in_b(piles);
		piles->p_b[bindex][MARKER] = TO_PUSH;
		cpt--;
		nb++;
	}
	push_on_half_median(piles, nb);
	small_algov3(piles);
}
