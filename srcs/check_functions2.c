/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_functions2.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/20 13:03:02 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 13:13:19 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int		find_bigest_in_b(t_pile *piles)
{
	int index;
	int bigest_elt;
	int cpt;
	int bol;

	bol = 0;
	if ((*piles).size_b == 0)
		return (-1);
	if ((*piles).size_b == 1)
		return (0);
	bigest_elt = (*piles).p_b[(*piles).size_b - 1][DATA];
	cpt = (*piles).size_b - 2;
	while (cpt >= 0)
	{
		if ((*piles).p_b[cpt][DATA] > bigest_elt &&
				(*piles).p_b[cpt][MARKER] == FULL)
		{
			bol++;
			bigest_elt = (*piles).p_b[cpt][DATA];
			index = cpt;
		}
		cpt--;
	}
	index = (bol == 0) ? (*piles).size_b - 1 : index;
	return (index);
}

int		find_smallest_in_b(t_pile *piles)
{
	int index;
	int smallest_elt;
	int cpt;
	int bol;
	int comp_index;

	bol = 0;
	if ((*piles).size_b == 1)
		return (0);
	comp_index = (*piles).size_b - 1;
	smallest_elt = piles->p_b[comp_index][DATA];
	cpt = (*piles).size_b - 1;
	while (cpt--)
	{
		if ((*piles).p_b[cpt][DATA] < smallest_elt &&
				(*piles).p_b[cpt][MARKER] == FULL)
		{
			bol++;
			smallest_elt = (*piles).p_b[cpt][DATA];
			index = cpt;
		}
	}
	index = (bol == 0) ? comp_index : index;
	return (index);
}

int		b_is_sorted(t_pile piles)
{
	int cpt;

	if (piles.size_b == 1)
		return (1);
	cpt = piles.size_b - 2;
	while (cpt >= 0)
	{
		if (piles.p_b[cpt][DATA] > piles.p_b[cpt + 1][DATA])
			return (-1);
		cpt--;
	}
	return (1);
}

void	small_sort_b(t_pile *piles)
{
	clean_markers(piles);
	if (find_bigest_in_b(piles) == 2 && find_smallest_in_b(piles) == 1)
	{
		all_ops("rrb", piles, 1);
		all_ops("sb", piles, 1);
	}
	else if (find_smallest_in_b(piles) == 2 && find_bigest_in_b(piles) == 1)
		all_ops("rb", piles, 1);
	else if (find_smallest_in_b(piles) == 0 && find_bigest_in_b(piles) == 1)
		all_ops("sb", piles, 1);
	else if (find_smallest_in_b(piles) == 2 && find_bigest_in_b(piles) == 0)
	{
		all_ops("sb", piles, 1);
		all_ops("rrb", piles, 1);
	}
	else if (find_smallest_in_b(piles) == 1 && find_bigest_in_b(piles) == 0)
		all_ops("rrb", piles, 1);
}

void	clean_markers_a(t_pile *piles)
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
}
