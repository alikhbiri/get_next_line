/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 04:11:52 by alkhbiri          #+#    #+#             */
/*   Updated: 2024/12/18 02:07:21 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
int		check_newline(char *str);
char	*ft_strjoin(char *left, char *right);
char	*_read_line(int fd, char *prompt);
char	*_get_line(char	*prompt);
char	*update_rest(char *prompt);
char	*get_next_line(int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif