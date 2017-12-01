#include "get_next_line.h"

int		line_verif(char **line, char **tmp, int res, char **str)
{
	*str = NULL;
	if (res == 0 && ft_strlen(*tmp) > 0)
	{
		*line = *tmp;
		*tmp = NULL;
		return (1);
	}
	return (res);
}

char	*read_line(char *tmp)
{
	int		t;
	char	*line;

	t = 0;
	while (tmp[t] != '\n')
		t++;
	line = (char *)malloc((t + 1) * sizeof(char));
	line = ft_strncpy(line, tmp, t);
	line[t] = '\0';
	return (line);
}

char	*cpycat(char *s1, char *s2)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_memalloc(ft_strlen(s1) + ft_strlen(s2));
	s1 ? tmp = ft_strcpy(tmp, s1) : NULL;
	s1 ? tmp = ft_strncat(tmp, s2, ft_strlen(s2)) : NULL;
	//printf("%s\n", tmp);
	return (tmp);
}

int		get_next_line(int const fd, char **line)
{
	static char		*str = NULL;
	int				res;
	char			*buf;
	char			*tmp;

	if (fd < 0 || !line || BUFF_SIZE < 1 || BUFF_SIZE > 10000000)
		return (-1);
	buf = ft_strnew(BUFF_SIZE + 1);
	if (str == NULL)
		str = ft_memalloc(BUFF_SIZE);
	tmp = ft_strncpy(ft_memalloc(BUFF_SIZE), str, BUFF_SIZE);
	while (!(ft_strchr(tmp, '\n')))
	{
		if ((res = read(fd, buf, BUFF_SIZE)) < 1)
			return (line_verif(line, &tmp, res, &str));
		buf[res] = '\0';
		tmp = cpycat(tmp, buf);
	}
	*line = read_line(tmp);
	if (ft_strchr(tmp, '\n'))
		str = ft_strncpy(str, ft_strchr(tmp, '\n') + 1, BUFF_SIZE);
	free(tmp);
	free(buf);
	return (1);
}