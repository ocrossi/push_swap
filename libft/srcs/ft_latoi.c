/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <ocrossi@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 18:20:42 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/23 21:14:14 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

long long		ft_latoi(char *str)
{
	int			i;
	int			p;
	long long	r;

	r = 0;
	i = 0;
	p = 0;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\v' || str[i] ==
			'\n' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		p = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		return (0);
	while ((str[i] <= '9') && (str[i] >= '0'))
	{
		r = 10 * r + (str[i] - 48);
		i++;
	}
	if (p == 1)
		return (-r);
	else
		return (r);
}
