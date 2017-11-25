#include "libft.h"
#include "get_next_line.h"

static int				ft_line(char **line, char **str, int i)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	if (i != 0 && ft_strlen(*str) != 0)
	{
		while ((*str)[x] != '\n')
		{
			(*line)[x] = (*str)[x];
			x++;
		}
		(*line)[x] = '\0';
		x++;
		if ((*str)[0] == '\n')
		{
			while ((*str)[x])
				(*str)[y++] = (*str)[x++];
			(*str)[y] = 0;
			return (2);
		}
		while ((*str)[x])
			(*str)[y++] = (*str)[x++];
		(*save)[y] = '\0';
	}
	return (1);
}

static int				ft_realloc(char **str)
{
	char 		*tmp;

	if (!(tmp = ft_strnew(ft_strlen(*str))))
		return (0);
	ft_strcpy(tmp, *str);
	if (!(*str = ft_strnew(ft_strlen(tmp) + BUFF_SIZE)))
		return (0);
	ft_strcpy(*str, tmp);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	int			i;
	static char	*str;

	if (fd < 0 || !(str = ft_strnew(BUFF_SIZE)
		&& *line = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((i = read(fd, *line, BUFF_SIZE)) > 0)
	{
		if (!(ft_realloc(&str)))
			return (-1);
		ft_strcat(str, *line);
		if (ft_memchr(str, '\n', BUFF_SIZE))
			break ;
	}
	if ((ft_line(line, &str, i) == 2))
		return (1):
	if (ft_memcpy(*line, str, ft_strlen(*line)) == 0)
	{
		if (!(*line = ft_strdup("")))
			return (1);
		return(0);
	}
	return (1);
}
