/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b3.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/24 13:13:40 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 13:11:54 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		get_new_median_b(t_pile *piles)
{
	int delim;
	int bigest_index;
	int cpt;

	delim = counter_b(piles);
	cpt = delim / 2 + delim % 2;
	while (cpt)
	{
		bigest_index = find_bigest_in_b(piles);
		piles->p_b[bigest_index][MARKER] = TO_PUSH;
		cpt--;
	}
	return (piles->p_b[bigest_index][DATA]);
}

int		get_new_median_a(t_pile *piles)
{
	int delim;
	int smallest_index;
	int cpt;

	delim = counter_a(piles);
	cpt = delim / 2 + delim % 2;
	while (cpt)
	{
		smallest_index = find_smallest_in_a(piles);
		piles->p_a[smallest_index][MARKER] = TO_PUSH;
		cpt--;
	}
	return (piles->p_a[smallest_index][DATA]);
}

void	push_half_group_b_part2(t_pile *piles, int cpt)
{
	while (cpt)
	{
		all_ops("rrb", piles, 1);
		cpt--;
	}
	piles->p_b[piles->size_b - 1][MARKER] = USED;
}

void	push_half_group_b(t_pile *piles)
{
	int size_tot;
	int delim;
	int cpt;

	cpt = 0;
	delim = counter_b(piles) / 2 + counter_b(piles) % 2;
	size_tot = piles->size_b - 1;
	while (piles->p_b[piles->size_b - 1][MARKER] != USED)
	{
		if (size_tot == 0 || delim == 0)
			break ;
		if (piles->p_b[piles->size_b - 1][MARKER] == TO_PUSH)
		{
			delim--;
			all_ops("pa", piles, 1);
		}
		else
		{
			all_ops("rb", piles, 1);
			cpt++;
			size_tot--;
		}
	}
	push_half_group_b_part2(piles, cpt);
}

int		big_algo3(t_pile *piles)
{
	if (piles->size_a <= CDIV)
	{
		small_algov3(piles);
		return (0);
	}
	while (piles->size_a > CDIV)
		divide_and_conquer(piles);
	small_algov3(piles);
	piles->p_a[piles->size_a - 1][MARKER] = USED;
	while (piles->size_b > 0)
	{
		if (counter_b(piles) > CDIV)
			divide_top_b(piles);
		else
		{
			sort_from_b(piles);
			piles->p_a[piles->size_a - 1][MARKER] = USED;
		}
	}
	return (0);
}
