/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_functions.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/20 12:58:51 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/27 13:59:45 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int		sort_checker(t_pile piles)
{
	int cpt;
	int i;

	i = 0;
	cpt = piles.size_a - 1;
	if (piles.size_b != 0)
		return (-1);
	while (cpt >= 1)
	{
		if (piles.p_a[cpt][DATA] >= piles.p_a[cpt - 1][DATA])
			return (-1);
		cpt--;
	}
	return (1);
}

int		a_is_sorted(t_pile piles)
{
	int cpt;

	if (piles.size_a == 1)
		return (1);
	cpt = piles.size_a - 2;
	while (cpt >= 0)
	{
		if (piles.p_a[cpt][DATA] < piles.p_a[cpt + 1][DATA])
			return (-1);
		cpt--;
	}
	return (1);
}

int		detect_first_usable_elem_a(t_pile *piles)
{
	int cpt;

	cpt = piles->size_a - 1;
	while (cpt >= 0)
	{
		if ((*piles).p_a[cpt][MARKER] == FULL)
			return (cpt);
		cpt--;
	}
	return (piles->size_a - 1);
}

int		find_bigest_in_a(t_pile *piles)
{
	int index;
	int bigest_elt;
	int cpt;
	int bol;

	bol = 0;
	if ((*piles).size_a == 0)
		return (-1);
	if ((*piles).size_a == 1)
		return (0);
	bigest_elt = detect_first_usable_elem_a(piles);
	cpt = (*piles).size_a - 1;
	while (cpt >= 0)
	{
		if ((*piles).p_a[cpt][DATA] > bigest_elt &&
				(*piles).p_a[cpt][MARKER] == FULL)
		{
			bol++;
			bigest_elt = (*piles).p_a[cpt][DATA];
			index = cpt;
		}
		cpt--;
	}
	index = (bol == 0) ? (*piles).size_a - 1 : index;
	return (index);
}

int		find_smallest_in_a(t_pile *piles)
{
	int index;
	int smallest_elt;
	int cpt;
	int bol;
	int comp_index;

	bol = 0;
	if ((*piles).size_a == 1)
		return (0);
	comp_index = detect_first_usable_elem_a(piles);
	smallest_elt = piles->p_a[comp_index][DATA];
	cpt = (*piles).size_a - 1;
	while (cpt--)
	{
		if ((*piles).p_a[cpt][DATA] < smallest_elt &&
				(*piles).p_a[cpt][MARKER] == FULL)
		{
			bol++;
			smallest_elt = (*piles).p_a[cpt][DATA];
			index = cpt;
		}
	}
	index = (bol == 0) ? comp_index : index;
	return (index);
}
