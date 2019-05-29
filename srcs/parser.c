/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/23 18:21:19 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/27 14:40:02 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int		check_valid_str(char *str)
{
	int i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\v' ||
			str[i] == '\n' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (ft_error("invalid argument"));
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (ft_error("invalid argument"));
		i++;
	}
	return (1);
}

int		check_for_duplicate(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i <= ac - 1)
	{
		while (j <= ac - 1)
		{
			if (i != j && ft_latoi(av[i]) == ft_latoi(av[j]))
				return (ft_error("duplicate arguments"));
			j++;
		}
		j = 1;
		i++;
	}
	return (1);
}

void	check_valid_input(int ac, char **av)
{
	int cpt;

	cpt = ac - 1;
	check_for_duplicate(ac, av);
	while (cpt >= 1)
	{
		check_overflow(ft_latoi(av[cpt]));
		check_valid_str(av[cpt]);
		cpt--;
	}
}

int		check_for_duplicate2(int cpt, char **res)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < cpt)
	{
		while (j < cpt)
		{
			if (i != j && ft_latoi(res[i]) == ft_latoi(res[j]))
				return (ft_error("duplicate arguments"));
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	check_valid_input2(char **av, t_pile *piles)
{
	int		cpt;
	int		cpy;
	char	**res;
	char	**tmp;

	cpt = 0;
	res = ft_strsplit(av[1], ' ');
	tmp = res;
	while (*tmp != NULL)
	{
		tmp++;
		cpt++;
	}
	cpy = cpt;
	check_for_duplicate2(cpt, res);
	cpt--;
	while (cpt >= 0)
	{
		check_overflow(ft_latoi(res[cpt]));
		check_valid_str(res[cpt]);
		cpt--;
	}
	init_piles2(cpy, res, piles);
}
