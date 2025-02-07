/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhbiri <alkhbiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 04:12:32 by alkhbiri          #+#    #+#             */
/*   Updated: 2024/12/18 02:07:35 by alkhbiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

char	*ft_strjoin(char *left, char *right)
{
	size_t	len_left;
	size_t	len_right;
	char	*result;

	if (!left && !right)
		return (NULL);
	len_left = ft_strlen(left);
	len_right = ft_strlen(right);
	result = malloc(len_left + len_right + 1);
	if (!result)
	{
		free(left);
		return (NULL);
	}
	if (left)
		ft_strlcpy(result, left, len_left + 1);
	ft_strlcpy(result + len_left, right, len_right + 1);
	free(left);
	return (result);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	check_newline(char *str)
{
	int	index;

	if (!str)
		return (0);
	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}
