/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 15:59:02 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 17:34:12 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ret;
	char *s;

	if (!(s = (char*)malloc(sizeof(char) * size + 1)) || size == 0)
		return (NULL);
	ret = s;
	while (size + 1)
	{
		*s = '\0';
		s++;
		size--;
	}
	return (ret);
}
