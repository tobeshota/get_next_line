/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshota <toshota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:44:59 by toshota           #+#    #+#             */
/*   Updated: 2023/09/24 15:16:53 by toshota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <limits.h> // OPEN_MAX
# include <stdlib.h> // malloc, free
# include <unistd.h> // read

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// get_next_line_utils.c
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// get_next_line.c
char	*get_next_line(int fd);
char	*get_new_line(char **save, int fd);
char	*gnl_strjoin(char const *save, char const *buf, int read_size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

#endif
