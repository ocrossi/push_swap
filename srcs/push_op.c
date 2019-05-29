/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_op.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/24 01:11:25 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/27 14:37:56 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int		push_a(t_pile *piles)
{
	if ((*piles).size_b <= 0)
		return (1);
	(*piles).p_a[(*piles).size_a][DATA] =
		(*piles).p_b[(*piles).size_b - 1][DATA];
	(*piles).p_a[(*piles).size_a][MARKER] = FULL;
	(*piles).p_b[(*piles).size_b - 1][DATA] = EMPTY;
	(*piles).p_b[(*piles).size_b - 1][DATA] = EMPTY;
	(*piles).size_b--;
	(*piles).size_a++;
	return (0);
}

int		push_b(t_pile *piles)
{
	if ((*piles).size_a <= 0)
		return (1);
	(*piles).p_b[(*piles).size_b][DATA] =
		(*piles).p_a[(*piles).size_a - 1][DATA];
	(*piles).p_b[(*piles).size_b][MARKER] = FULL;
	(*piles).p_a[(*piles).size_a - 1][DATA] = EMPTY;
	(*piles).p_a[(*piles).size_a - 1][DATA] = EMPTY;
	(*piles).size_a--;
	(*piles).size_b++;
	return (0);
}

int		push_op(t_pile *piles, char *str)
{
	if (ft_strcmp(str, "pa") == 0 && ft_strlen(str) == 2)
		return (push_a(piles));
	if (ft_strcmp(str, "pb") == 0 && ft_strlen(str) == 2)
		return (push_b(piles));
	return (-1);
}
