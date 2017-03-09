/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:19:13 by pluu              #+#    #+#             */
/*   Updated: 2017/03/02 16:22:01 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*curr;

	if (line == NULL || fd < 0 || BUFF_SIZE < 0)
		return (-1);
	curr = append_search_fd(fd, &head);
	while (curr->len || (curr->ret = read(curr->fd, curr->buf, BUFF_SIZE)) > 0)
	{
		(curr->buf)[(curr->ret)] = '\0';
		if (validate_line(curr, line))
			break ;
		else
		{
			if (((curr->len_cnt + curr->len)) == (int)ft_strlen(curr->buf) ||
					curr->len_cnt - curr->len == 0)
				curr->len = 0;
		}
	}
	if ((curr->flag_nl == 1 && curr->ret == 0) || curr->ret > 0)
	{
		curr->flag_nl = 0;
		return (1);
	}
	return (curr->ret == 0 ? 0 : -1);
}

int		validate_line(t_gnl *curr, char **line)
{
	curr->len_cnt = 0;
	while (*(curr->pbuf))
	{
		if (*(curr->pbuf) == '\n')
		{
			populate_line(curr, line);
			(curr->pbuf)++;
			if (*(curr->pbuf))
				curr->len = (curr->pbuf - curr->buf);
			else
			{
				curr->pbuf = curr->buf;
				curr->flag_nl = 0;
				curr->len = 0;
			}
			return (1);
		}
		(curr->pbuf)++;
		(curr->len_cnt)++;
	}
	populate_line(curr, line);
	curr->pbuf = curr->buf;
	curr->flag_nl = 1;
	return (0);
}

int		populate_line(t_gnl *curr, char **line)
{
	if (curr->flag_nl == 1)
	{
		curr->tmp = ft_strnew(ft_strlen(*line));
		ft_strcpy(curr->tmp, *line);
		ft_memdel((void**)line);
		*line = ft_strnew(ft_strlen(curr->tmp) + curr->len_cnt);
		ft_strcpy(*line, curr->tmp);
		ft_strncat(*line, curr->buf, (curr->pbuf - curr->buf));
		ft_memdel((void**)(&(curr->tmp)));
	}
	else
	{
		*line = ft_strnew(curr->len_cnt);
		ft_memcpy(*line, (curr->buf + curr->len), curr->len_cnt);
		(*line)[(curr->len_cnt)] = '\0';
	}
	return (1);
}

t_gnl	*append_search_fd(int fd, t_gnl **head)
{
	t_gnl		*beg;
	t_gnl		*new;

	beg = NULL;
	new = NULL;
	if (*head == NULL)
	{
		*head = (t_gnl*)malloc(sizeof(t_gnl));
		(*head)->fd = fd;
		(*head)->pbuf = (*head)->buf;
		(*head)->len = 0;
		(*head)->flag_nl = 0;
		(*head)->next = NULL;
		return (*head);
	}
	else
		return (app_hlpr(fd, head, beg, new));
}

t_gnl	*app_hlpr(int fd, t_gnl **head, t_gnl *beg, t_gnl *new)
{
	beg = *head;
	while (*head)
	{
		if ((*head)->fd == fd)
		{
			new = *head;
			*head = beg;
			return (new);
		}
		else if ((*head)->next == NULL)
			break ;
		*head = (*head)->next;
	}
	new = (t_gnl*)malloc(sizeof(t_gnl));
	new->fd = fd;
	new->pbuf = new->buf;
	new->len = 0;
	new->flag_nl = 0;
	new->next = NULL;
	(*head)->next = new;
	*head = beg;
	return (new);
}
