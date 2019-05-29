/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   revrotate_op.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/24 03:07:44 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 13:09:43 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int		revrotate_a(t_pile *piles)
{
	int cpt;

	cpt = 0;
	if ((*piles).size_a <= 1)
		return (1);
	while (cpt < (*piles).size_a - 1)
	{
		ft_swap(&((*piles).p_a[cpt][DATA]), &((*piles).p_a[cpt + 1][DATA]));
		ft_swap(&((*piles).p_a[cpt][MARKER]), &((*piles).p_a[cpt + 1][MARKER]));
		cpt++;
	}
	return (1);
}

int		revrotate_b(t_pile *piles)
{
	int cpt;

	cpt = 0;
	if ((*piles).size_b <= 1)
		return (1);
	while (cpt < (*piles).size_b - 1)
	{
		ft_swap(&((*piles).p_b[cpt][DATA]), &((*piles).p_b[cpt + 1][DATA]));
		ft_swap(&((*piles).p_b[cpt][MARKER]), &((*piles).p_b[cpt + 1][MARKER]));
		cpt++;
	}
	return (1);
}

int		double_revrotate(t_pile *piles)
{
	revrotate_a(piles);
	revrotate_b(piles);
	return (1);
}

int		revrotate_op(t_pile *piles, char *str)
{
	if (ft_strcmp(str, "rra") == 0 && ft_strlen(str) == 3)
		return (revrotate_a(piles));
	if (ft_strcmp(str, "rrb") == 0 && ft_strlen(str) == 3)
		return (revrotate_b(piles));
	if (ft_strcmp(str, "rrr") == 0 && ft_strlen(str) == 3)
		return (double_revrotate(piles));
	return (-1);
}

int		all_ops(char *str, t_pile *piles, int a)
{
	if (push_op(piles, str) == -1 && swap_op(piles, str) == -1 &&
			rotate_op(piles, str) == -1 && revrotate_op(piles, str) == -1)
		return (ft_error("wrong input command"));
	(*piles).op_nbr++;
	if (a == 1)
		ft_putendl(str);
	return (1);
}
