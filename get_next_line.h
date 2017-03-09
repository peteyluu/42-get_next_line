/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:18:30 by pluu              #+#    #+#             */
/*   Updated: 2017/03/02 17:02:11 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# define BUFF_SIZE 32

typedef struct		s_gnl
{
	int				fd;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*pbuf;
	int				len;
	int				flag_nl;
	char			*tmp;
	int				len_cnt;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);
t_gnl				*append_search_fd(int fd, t_gnl **head);
t_gnl				*app_hlpr(int fd, t_gnl **head, t_gnl *beg, t_gnl *new);
int					validate_line(t_gnl *curr, char **line);
int					populate_line(t_gnl *curr, char **line);

#endif
