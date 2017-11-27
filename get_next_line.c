/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 08:00:00 by tfavart           #+#    #+#             */
/*   Updated: 2017/11/27 15:48:11 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char				*ft_realloc(char * str)
{
	char			*tmp;

	if (str == NULL)
		if (!(str = ft_strnew(BUFF_SIZE)))
			return (0);
	if (str != NULL)
	{
		tmp = str;
		if (!(str = ft_strnew(ft_strlen(tmp) + BUFF_SIZE)))
			return (0);
		ft_strcpy(str, tmp);
		free(tmp);
	}
	return (str);
}

void				ft_line(char **line, char **str)
{
	int				i;
	int				x;
	char			*tmp;

	i = 0;
	x = 0;
	tmp = *str;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if (!(*line = ft_strnew(i)))
		return ;
	while (x < i)
	{
		(*line)[x] = (*str)[x];
		x++;
	}
	i++;
	*str = ft_strsub(*str, i, ft_strlen(*str));
	free(tmp);
}

int					get_next_line(int fd, char **line)
{
	static char		*str;
	int				red;

	if (!(*line = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((red = read(fd, *line, BUFF_SIZE)))
	{
		if (!(str = ft_realloc(str)))
			return (-1);
		ft_strncat(str, *line, ft_strlen(str) + BUFF_SIZE);
		if (ft_strchr(str, '\n'))
			break;
	}
	ft_line(line, &str);
	if (red >= 0 && str[0] != '\0')
		return (1);
	else
	{
		free(str);
		return (0);
	}
}
