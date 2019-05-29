/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/27 14:28:29 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/27 14:29:01 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int		ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
	return (-1);
}

int		check_overflow(long long a)
{
	if (a < -2147483648 || a > 2147483647)
		return (ft_error("int overflow on arguments"));
	return (1);
}
