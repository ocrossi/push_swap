/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/14 20:47:23 by ocrossi      #+#   ##    ##    #+#       */
/*   Updated: 2019/05/28 13:08:12 by ocrossi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char		*trim_and_del(char **ct)
{
	char	*tmp;
	char	*ret;
	int		len_line;
	int		tst;

	if ((*ct)[0] == '\0')
		return (NULL);
	len_line = ft_strlen(*ct) - ft_strlen(ft_strchr(*ct, '\n'));
	ret = ft_strndup(*ct, len_line);
	tst = ((*ct)[len_line] == '\n') ? 1 : 0;
	if (tst == 1)
		tmp = ft_strdup(*ct + len_line + 1);
	else
		tmp = NULL;
	free(*ct);
	*ct = ft_strdup(tmp);
	free(tmp);
	if (len_line == 0)
		return (ft_strnew(1));
	return (ret);
}

static int		checks_eof(char **ct, char **line)
{
	if (!(*ct))
		return (0);
	if ((*ct)[0] == '\0')
		return (0);
	if (!ft_strchr(*ct, '\n'))
	{
		*line = ft_strdup(*ct);
		free(*ct);
		*ct = ft_strnew(1);
		return (1);
	}
	else
		return (1);
}

static int		read_line(const int fd, char **ct, char **line)
{
	int		rd_bytes;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	if (ft_strchr(*ct, '\n'))
	{
		*line = trim_and_del(ct);
		return (1);
	}
	while ((rd_bytes = read(fd, buf, BUFF_SIZE)))
	{
		buf[rd_bytes] = '\0';
		tmp = ft_strdup(*ct);
		free(*ct);
		*ct = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_strchr(*ct, '\n'))
			break ;
	}
	if (rd_bytes == 0)
		return (checks_eof(ct, line));
	*line = trim_and_del(ct);
	return (1);
}

static t_list	*get_the_node(t_file elem, t_list **begin)
{
	t_list	*tmp;

	tmp = *begin;
	while (tmp)
	{
		if ((((t_file*)(tmp->content))->fd) == elem.fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew(&elem, sizeof(elem));
	ft_lstadd(begin, tmp);
	tmp = *begin;
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*begin_list;
	t_list			*curr;
	t_file			elem;
	int				ret;

	elem.fd = fd;
	elem.str = NULL;
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || (read(fd, NULL, 0) == -1))
		return (-1);
	curr = get_the_node(elem, &begin_list);
	ret = read_line(elem.fd, &((t_file*)(curr->content))->str, line);
	return (ret);
}
