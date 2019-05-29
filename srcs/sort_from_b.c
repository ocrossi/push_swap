/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_from_b.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/27 13:44:16 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 13:17:00 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	small_sort_a(t_pile *piles)
{
	if (find_bigest_in_a(piles) == 1 && find_smallest_in_a(piles) == 2)
	{
		all_ops("rra", piles, 1);
		all_ops("sa", piles, 1);
	}
	else if (find_smallest_in_a(piles) == 1 && find_bigest_in_a(piles) == 0)
		all_ops("sa", piles, 1);
	else if (find_smallest_in_a(piles) == 1 && find_bigest_in_a(piles) == 2)
		all_ops("ra", piles, 1);
	else if (find_smallest_in_a(piles) == 0 && find_bigest_in_a(piles) == 2)
	{
		all_ops("sa", piles, 1);
		all_ops("rra", piles, 1);
	}
	else if (find_smallest_in_a(piles) == 0 && find_bigest_in_a(piles) == 1)
		all_ops("rra", piles, 1);
}

int		detect_first_usable_elem_b(t_pile *piles)
{
	int cpt;

	cpt = piles->size_b - 1;
	while (cpt >= 0)
	{
		if ((*piles).p_b[cpt][MARKER] == FULL)
			return (cpt);
		cpt--;
	}
	return (piles->size_b - 1);
}

void	sort_from_b_part2(t_pile *piles, int bigest, int bigest_index, int *nb)
{
	if (piles->p_b[piles->size_b - 1][DATA] == bigest)
	{
		all_ops("pa", piles, 1);
		*nb -= 1;
	}
	else if (piles->p_b[piles->size_b - 2][DATA] == bigest)
	{
		all_ops("sb", piles, 1);
		all_ops("pa", piles, 1);
		*nb -= 1;
	}
	else if (bigest_index < piles->size_b / 2)
	{
		while (piles->p_b[piles->size_b - 1][DATA] != bigest)
			all_ops("rrb", piles, 1);
		all_ops("pa", piles, 1);
		*nb -= 1;
	}
	else
	{
		while (piles->p_b[piles->size_b - 1][DATA] != bigest)
			all_ops("rb", piles, 1);
		all_ops("pa", piles, 1);
		*nb -= 1;
	}
}

void	sort_from_b(t_pile *piles)
{
	int nb;
	int bigest;
	int bigest_index;

	nb = counter_b(piles);
	if (piles->size_b == 1)
	{
		all_ops("pa", piles, 1);
		return ;
	}
	while (nb)
	{
		bigest_index = find_bigest_in_b(piles);
		bigest = piles->p_b[bigest_index][DATA];
		sort_from_b_part2(piles, bigest, bigest_index, &nb);
	}
}
