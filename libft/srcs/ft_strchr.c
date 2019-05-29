/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 11:55:53 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 15:22:43 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	if (c == 0)
	{
		while (*(char*)s)
			s++;
		return ((char*)s);
	}
	while (*(char*)s != '\0')
	{
		if (*(char*)s == (char)c)
			return ((char*)s);
		s++;
	}
	return (NULL);
}
