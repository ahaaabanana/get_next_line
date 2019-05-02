/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <tgrandpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:23:13 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/05/02 15:07:21 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char			str[BUFF_SIZE + 1];
	int				ret;
	static char		*str_sub;

	*line = malloc(1);
	**line = 0;
	while ((ret = read(fd, str, BUFF_SIZE)))
	{
		str[ret] = 0;
		*line = ft_strjoin(*line, str);	
		if ((str_sub = strchr(str, 10)))
			break ;
	}
	printf("STR=%s\n", str);
	printf("SUB=%s\n", str_sub);
	printf("%p, %p\n", str_sub, str_sub + 1);
	str_sub = ft_strsub(str_sub, 1, ft_strlen(str_sub));
	printf("%p\n", str_sub);
	printf("SUBAFTER=%s", str_sub);
	if (ret == 0)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;

	fd = open("in", O_RDONLY);
	get_next_line(fd, &line);
	/* while (get_next_line(fd, &line))
		printf("LINE=%s\n", line); */
	close(fd);
	return (0);
}