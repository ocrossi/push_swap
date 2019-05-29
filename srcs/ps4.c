/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps4.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/22 15:44:18 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 13:15:47 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	sa3_g(t_pile *piles)
{
	int id_smallest;
	int smallest;

	id_smallest = find_smallest_in_a(piles);
	smallest = piles->p_a[id_smallest][DATA];
	if (id_smallest == piles->size_a - 2)
	{
		all_ops("sa", piles, 1);
		all_ops("pb", piles, 1);
	}
	else if (id_smallest >= piles->size_a / 2)
	{
		while (piles->p_a[piles->size_a - 1][DATA] != smallest)
			all_ops("ra", piles, 1);
		all_ops("pb", piles, 1);
	}
	else
	{
		while (piles->p_a[piles->size_a - 1][DATA] != smallest)
			all_ops("rra", piles, 1);
		all_ops("pb", piles, 1);
	}
}

void	special_case(t_pile *piles)
{
	int cpt;

	cpt = counter_a(piles);
	if (cpt == 1)
	{
		if (piles->p_a[piles->size_a - 1][MARKER] == TO_PUSH)
			piles->p_a[piles->size_a - 1][MARKER] = FULL;
		return ;
	}
	if (cpt == 2 && a_is_sorted(*piles) != 1)
	{
		all_ops("sa", piles, 1);
		if (piles->p_a[piles->size_a - 1][MARKER] == TO_PUSH)
			piles->p_a[piles->size_a - 1][MARKER] = FULL;
		if (piles->p_a[piles->size_a - 2][MARKER] == TO_PUSH)
			piles->p_a[piles->size_a - 2][MARKER] = FULL;
	}
}

int		small_algov3_part2(t_pile *piles)
{
	special_case(piles);
	if (a_is_sorted(*piles) == 1)
		return (0);
	if (piles->size_a == 3)
		small_sort_a(piles);
	if (piles->size_a == 2 && a_is_sorted(*piles) != 1)
	{
		all_ops("sa", piles, 1);
		if (piles->p_a[piles->size_a - 1][MARKER] == TO_PUSH)
			piles->p_a[piles->size_a - 1][MARKER] = FULL;
	}
	return (1);
}

int		small_algov3(t_pile *piles)
{
	if (piles->size_b == 0)
	{
		while (a_is_sorted(*piles) != 1)
		{
			if (piles->size_a == 3)
				small_sort_a(piles);
			sa3_g(piles);
		}
		while (piles->size_b != 0)
			all_ops("pa", piles, 1);
	}
	else
	{
		if (small_algov3_part2(piles) == 0)
			return (0);
		while (a_is_sorted(*piles) != 1)
			sa3_g(piles);
		while (piles->p_b[piles->size_b - 1][MARKER] != USED
				&& piles->size_b > 0)
			all_ops("pa", piles, 1);
	}
	return (0);
}
