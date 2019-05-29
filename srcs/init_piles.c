/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_piles.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/23 18:25:24 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/27 14:37:01 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int		init_piles_part2(t_pile *piles, int cpt)
{
	if (!((*piles).p_a = (int**)malloc(sizeof(int*) * cpt)))
		return (ft_error("allocation failure for pile a"));
	if (!((*piles).p_b = (int**)malloc(sizeof(int*) * cpt)))
		return (ft_error("allocation failure for pile b"));
	return (0);
}

int		init_piles(int ac, char **av, t_pile *piles)
{
	int cpt;
	int i;

	i = 1;
	cpt = ac - 1;
	init_piles_part2(piles, cpt);
	(*piles).size_a = ac - 1;
	(*piles).size_b = 0;
	(*piles).op_nbr = 0;
	cpt--;
	while ((cpt + 1) != 0)
	{
		if (!(((*piles).p_a[cpt]) = (int*)malloc(sizeof(int) * 2)))
			return (ft_error("allocation failure for pile a"));
		if (!(((*piles).p_b[cpt]) = (int*)malloc(sizeof(int) * 2)))
			return (ft_error("allocation failure for pile b"));
		(*piles).p_a[cpt][MARKER] = FULL;
		(*piles).p_a[cpt][DATA] = ft_atoi(av[i]);
		(*piles).p_b[cpt][MARKER] = EMPTY;
		(*piles).p_b[cpt][DATA] = 0;
		cpt--;
		i++;
	}
	return (1);
}

int		init_piles2_part2(t_pile *piles, int cpt)
{
	if (!((*piles).p_a = (int**)malloc(sizeof(int*) * cpt)))
		return (ft_error("allocation failure for pile a"));
	if (!((*piles).p_b = (int**)malloc(sizeof(int*) * cpt)))
		return (ft_error("allocation failure for pile b"));
	return (0);
}

int		init_piles2(int cpt, char **res, t_pile *piles)
{
	int i;

	i = 0;
	init_piles2_part2(piles, cpt);
	(*piles).size_a = cpt;
	(*piles).size_b = 0;
	(*piles).op_nbr = 0;
	cpt--;
	while (cpt >= 0)
	{
		if (!(((*piles).p_a[cpt]) = (int*)malloc(sizeof(int) * 2)))
			return (ft_error("allocation failure for pile a"));
		if (!(((*piles).p_b[cpt]) = (int*)malloc(sizeof(int) * 2)))
			return (ft_error("allocation failure for pile b"));
		check_overflow(ft_latoi(res[cpt]));
		(*piles).p_a[cpt][MARKER] = FULL;
		(*piles).p_a[cpt][DATA] = ft_atoi(res[i]);
		(*piles).p_b[cpt][MARKER] = EMPTY;
		(*piles).p_b[cpt][DATA] = 0;
		cpt--;
		i++;
	}
	return (1);
}
