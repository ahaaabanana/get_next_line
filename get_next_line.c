/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:23:13 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/05/05 18:44:11 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char 	*stat_str;
	char			*x;
	char			str[BUFF_SIZE + 1];
	int				ret;
	
	if (fd == -1)
		return (-1);	
	stat_str = ft_strnew(1);	
	while ((ret = read(fd, str, BUFF_SIZE)))
	{
		str[ret] = 0;
		x = ft_strjoin(stat_str, str);
		free(stat_str);
		stat_str = x;
		if (ft_strchr(str, 10))
			break ;
	}
	printf("X = %s\n\nSTATSTR=%s\n\n", x, stat_str);
	return (1);
}

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		gnl;

	fd = open("in", O_RDONLY);
	gnl = get_next_line(fd, &line);
	printf("LINE=%s", line);
	close(fd);
	return (0);
}