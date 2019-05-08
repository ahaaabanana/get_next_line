/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whybread <whybread@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:23:13 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/05/07 23:52:41 by whybread         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line, int counter)
{
	static char 	*stat_str;
	char			*x;
	char			str[BUFF_SIZE + 1];
	int				ret;
	
	printf("COUNTER = %d\n\n", counter);
	if (fd == -1 || line == NULL)
		return (-1);
	x = stat_str;
	if (x && (stat_str = ft_strchr(x + 1, 10)))
	{
		printf("STATSTR=%s\n\n", stat_str);
		printf("X=%s\n\n", x);
		*line = ft_strsub(x + 1, 0, ft_strlen(x + 1) - ft_strlen(stat_str));
		free(x);
		printf("TEST\n\n");
	}
	else
	{
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
		stat_str = ft_strchr(stat_str, 10);
		*line = ft_strsub(x, 0, ft_strlen(x) - ft_strlen(stat_str));
		free(x);
	}
	printf("LINE=%s\n\n", *line);
	printf("STATSTR=%s\n\n", stat_str);
	printf("X=%s\n\n", x);
	return (1);
}

int		main(int argc, char **argv)
{
	char	line[10];
	int		fd;
	int		gnl;
	int		counter = 0;

	fd = open("in", O_RDONLY);
	// printf("%p", line);
	// get_next_line(fd, &line, counter++);
	// get_next_line(fd, &line, counter);
	close(fd);
	return (0);
}










