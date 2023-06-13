/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:45:02 by toshota           #+#    #+#             */
/*   Updated: 2023/06/13 13:07:18 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;
	size_t	max_copy_size;

	if (dest == NULL && size == 0)
		return (ft_strlen(src));
	i = 0;
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	if (size <= dlen)
		return (size + slen);
	max_copy_size = size - dlen - 1;
	while (src[i] && i < max_copy_size)
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (slen + dlen);
}

char	*gnl_strjoin(char const *tmp, char const *buf, int read_size)
{
	char	*result;

	if (tmp == NULL && read_size == 0)
		return (NULL);
	if (tmp == NULL)
		return (ft_strdup(buf));
	result = (char *)malloc((ft_strlen(tmp) + ft_strlen(buf) + 1)
			* sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, tmp, ft_strlen(tmp) + 1);
	ft_strlcpy(result + ft_strlen(tmp), buf, ft_strlen(buf) + 1);
	return (result);
}

char	*get_new_line(char **save, int fd)
{
	int		read_size;
	char	*buf;
	char	*tmp;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	while (1)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_size] = '\0';
		tmp = *save;
		*save = gnl_strjoin(tmp, buf, read_size);
		free(tmp);
		if (*save == NULL || read_size != BUFFER_SIZE || ft_strchr(*save,
				'\n') != NULL)
			break ;
	}
	free(buf);
	return (*save);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*line;
	char		*tmp;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (get_new_line(&save[fd], fd) == NULL)
		return (NULL);
	if (ft_strchr(save[fd], '\n') != NULL)
	{
		line = ft_substr(save[fd], 0, ft_strchr(save[fd], '\n') - save[fd] + 1);
		tmp = save[fd];
		save[fd] = ft_strdup(ft_strchr(tmp, '\n') + 1);
		free(tmp);
	}
	else
	{
		if (*save[fd] == '\0')
			line = NULL;
		else
			line = ft_strdup(save[fd]);
		free(save[fd]);
		save[fd] = NULL;
	}
	return (line);
}
