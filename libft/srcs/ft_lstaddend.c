/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstaddend.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 12:13:01 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 12:39:42 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **begin, t_list *new)
{
	t_list *tmp;

	if (begin || !(*begin) || !new)
		return ;
	tmp = *begin;
	while (tmp->next)
	{
		ft_lstprintone(tmp);
		tmp = tmp->next;
	}
	tmp->next = new;
}
