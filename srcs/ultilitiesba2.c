/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ultilitiesba2.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/24 12:34:25 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 13:17:27 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		scan_the_conquered(t_pile *piles)
{
	int cpt;
	int used;

	used = 0;
	cpt = piles->size_a - 1;
	while (cpt > (piles->size_a - 1) / 2)
	{
		if (piles->p_a[cpt][MARKER] == USED)
			used++;
		cpt--;
	}
	if (used >= CDIV / 2)
		return (1);
	return (0);
}

void	push_the_conquered(t_pile *piles)
{
	int cpt;

	cpt = CDIV;
	if (piles->size_a > 2 && piles->p_a[piles->size_a - 2][MARKER] == USED)
	{
		while (piles->size_a > 2 && piles->p_a[piles->size_a - 2][MARKER]
				== USED)
		{
			all_ops("sa", piles, 1);
			all_ops("pb", piles, 1);
			cpt--;
		}
	}
	while (cpt > 0)
	{
		if (piles->p_a[piles->size_a - 1][MARKER] == USED)
		{
			all_ops("pb", piles, 1);
			cpt--;
			if (cpt == 0)
				break ;
		}
		all_ops("rra", piles, 1);
	}
	piles->p_b[piles->size_b - 1][MARKER] = USED;
}

int		check_layer_a(t_pile *piles)
{
	int cpt;
	int nb;

	nb = 0;
	if (piles->size_a == 0)
		return (-1);
	cpt = piles->size_a - 1;
	if (piles->p_a[cpt][MARKER] == USED)
		return (-1);
	while (cpt)
	{
		if (piles->p_a[cpt][MARKER] == USED)
			break ;
		nb++;
		cpt--;
	}
	if (nb < CDIV)
		return (1);
	return (-1);
}

int		counter_a(t_pile *piles)
{
	int cpt;
	int ret;

	if (piles->size_a < 1)
		return (0);
	cpt = piles->size_a - 1;
	ret = 0;
	if (piles->p_a[piles->size_a - 1][MARKER] == USED)
		return (0);
	while (cpt)
	{
		if (piles->p_a[cpt][MARKER] == USED)
			break ;
		cpt--;
		ret++;
	}
	return (ret);
}
