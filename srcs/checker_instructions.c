/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker_instructions.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/23 18:15:37 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 13:18:00 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_instructions(t_list *begin, t_pile *piles)
{
	if (begin == NULL)
		return ;
	if (begin->next)
		exec_instructions(begin->next, piles);
	if (begin->content != NULL)
		all_ops((char*)(begin->content), piles, 0);
}

void	get_the_list(char *line, t_list **begin)
{
	t_list *tmp;

	tmp = *begin;
	while (tmp)
		tmp = tmp->next;
	tmp = ft_lstnew(line, sizeof(line));
	ft_lstadd(begin, tmp);
}

int		checker_instructions(t_pile *piles)
{
	static t_list	*begin;
	char			*line;
	int				i;

	i = 0;
	while (get_next_line(0, &line))
	{
		get_the_list(line, &begin);
		ft_strdel(&line);
	}
	exec_instructions(begin, piles);
	return (sort_checker(*piles));
}
