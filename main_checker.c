/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_checker.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/23 18:09:00 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 13:19:19 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./srcs/includes/push_swap.h"

int		main(int ac, char **av)
{
	t_pile	piles;

	if (ac == 1)
		return (ft_error("please insert arguments"));
	else if (ac > 2)
	{
		check_valid_input(ac, av);
		init_piles(ac, av, &piles);
	}
	else if (ac == 2)
		check_valid_input2(av, &piles);
	if (checker_instructions(&piles) == -1)
		ft_putendl("KO");
	else
		ft_putendl("OK");
	free_piles(&piles);
	return (0);
}
