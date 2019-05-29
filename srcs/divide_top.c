/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   divide_top.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/26 23:36:54 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 13:14:23 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		divide_top_a_part2(t_pile *piles, int test)
{
	int cpt;

	cpt = 0;
	while (test)
	{
		if (test == 0)
			break ;
		if (piles->p_a[piles->size_a - 1][MARKER] == TO_PUSH)
		{
			all_ops("pb", piles, 1);
			test--;
		}
		else
		{
			all_ops("ra", piles, 1);
			cpt++;
		}
	}
	piles->p_b[piles->size_b - 1][MARKER] = USED;
	while (cpt)
	{
		all_ops("rra", piles, 1);
		cpt--;
	}
	return (test);
}

void	divide_top_a(t_pile *piles)
{
	int nb;
	int bol;
	int test;

	bol = 0;
	nb = counter_a(piles);
	get_new_median_a(piles);
	test = counter_a(piles) / 2 + counter_a(piles) % 2;
	while (nb >= CDIV)
	{
		if (nb < CDIV && bol >= 1)
			break ;
		bol++;
		nb = counter_a(piles);
		test = divide_top_a_part2(piles, test);
		if (nb >= CDIV)
		{
			test = counter_a(piles) / 2 + counter_a(piles) % 2;
			get_new_median_a(piles);
		}
		if (nb < CDIV && bol >= 1)
			break ;
	}
}

void	divide_top_b(t_pile *piles)
{
	int value;

	if (piles->size_b == 0)
		ft_error("divide top b");
	value = get_new_median_b(piles);
	push_half_group_b(piles);
	piles->p_b[piles->size_b - 1][MARKER] = USED;
	if (counter_a(piles) > CDIV)
	{
		divide_top_a(piles);
		small_algov3(piles);
		piles->p_a[piles->size_a - 1][MARKER] = USED;
	}
	if (a_is_sorted(*piles) != 1)
		small_algov3(piles);
}
