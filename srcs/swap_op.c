/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   swap_op.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/23 23:36:34 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/26 17:02:42 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int		swap_a(t_pile *piles)
{
	int cpt;

	cpt = (*piles).size_a - 1;
	if ((*piles).size_a <= 1)
		return (1);
	ft_swap(&((*piles).p_a[cpt][DATA]), &((*piles).p_a[cpt - 1][DATA]));
	ft_swap(&((*piles).p_a[cpt][MARKER]), &((*piles).p_a[cpt - 1][MARKER]));
	return (1);
}

int		swap_b(t_pile *piles)
{
	int cpt;

	cpt = (*piles).size_b - 1;
	if ((*piles).size_b <= 1)
		return (1);
	ft_swap(&((*piles).p_b[cpt][DATA]), &((*piles).p_b[cpt - 1][DATA]));
	ft_swap(&((*piles).p_b[cpt][MARKER]), &((*piles).p_b[cpt - 1][MARKER]));
	return (1);
}

int		double_swap(t_pile *piles)
{
	swap_a(piles);
	swap_b(piles);
	return (1);
}

int		swap_op(t_pile *piles, char *str)
{
	if (ft_strcmp(str, "sa") == 0 && ft_strlen(str) == 2)
		return (swap_a(piles));
	if (ft_strcmp(str, "sb") == 0 && ft_strlen(str) == 2)
		return (swap_b(piles));
	if (ft_strcmp(str, "ss") == 0 && ft_strlen(str) == 2)
		return (double_swap(piles));
	return (-1);
}
