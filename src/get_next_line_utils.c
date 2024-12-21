/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdumitru <mdumitru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:12:24 by mdumitru          #+#    #+#             */
/*   Updated: 2024/12/16 13:29:51 by mdumitru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strchr(const char *str, int c)
{
	while (*str != (char)c)
		if (!*str++)
			return (0);
	return ((char *)str);
}

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*result;
	char	*tmp_s1;

	tmp_s1 = s1;
	if (!s1 || !s2)
		return (NULL);
	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = malloc(s1_len + s2_len + 1);
	if (!result)
		return (NULL);
	while (*tmp_s1)
		result[i++] = *tmp_s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	free(s1);
	return (result);
}

static char	*ft_free(char *str, int flag)
{
	if (flag)
		free(str);
	return (NULL);
}

char	*gnl_substr(char *str, unsigned int start, size_t len, int flag)
{
	char	*sub_str;
	size_t	s_len;
	size_t	i;

	if (!str[0])
		return (ft_free(str, flag));
	s_len = ft_strlen(str);
	if (len > s_len)
		len = s_len;
	sub_str = malloc(len + 1);
	if (!sub_str)
		return (NULL);
	i = 0;
	while (i + start < s_len && len--)
	{
		sub_str[i] = str[start + i];
		i++;
	}
	sub_str[i] = '\0';
	ft_free(str, flag);
	return (sub_str);
}
