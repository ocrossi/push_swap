/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rotate_op.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/24 03:00:43 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/27 14:19:52 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int		rotate_a(t_pile *piles)
{
	int cpt;

	cpt = (*piles).size_a - 1;
	if ((*piles).size_a <= 1)
		return (1);
	while (cpt >= 1)
	{
		ft_swap(&((*piles).p_a[cpt][DATA]), &((*piles).p_a[cpt - 1][DATA]));
		ft_swap(&((*piles).p_a[cpt][MARKER]), &((*piles).p_a[cpt - 1][MARKER]));
		cpt--;
	}
	return (1);
}

int		rotate_b(t_pile *piles)
{
	int cpt;

	cpt = (*piles).size_b - 1;
	if ((*piles).size_b <= 1)
		return (1);
	while (cpt >= 1)
	{
		ft_swap(&((*piles).p_b[cpt][DATA]), &((*piles).p_b[cpt - 1][DATA]));
		ft_swap(&((*piles).p_b[cpt][MARKER]), &((*piles).p_b[cpt - 1][MARKER]));
		cpt--;
	}
	return (1);
}

int		double_rotate(t_pile *piles)
{
	rotate_a(piles);
	rotate_b(piles);
	return (1);
}

int		rotate_op(t_pile *piles, char *str)
{
	if (ft_strcmp(str, "ra") == 0 && ft_strlen(str) == 2)
		return (rotate_a(piles));
	if (ft_strcmp(str, "rb") == 0 && ft_strlen(str) == 2)
		return (rotate_b(piles));
	if (ft_strcmp(str, "rr") == 0 && ft_strlen(str) == 2)
		return (double_rotate(piles));
	return (-1);
}
