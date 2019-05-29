/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_ps.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/06 15:30:44 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/27 15:45:19 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./srcs/includes/push_swap.h"

int		main(int ac, char **av)
{
	t_pile piles;

	if (ac == 1)
		return (ft_error("please insert arguments"));
	else if (ac > 2)
	{
		check_valid_input(ac, av);
		init_piles(ac, av, &piles);
	}
	else if (ac == 2)
		check_valid_input2(av, &piles);
	big_algo3(&piles);
	free_piles(&piles);
	return (0);
}
