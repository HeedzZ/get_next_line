/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:59:04 by ymostows          #+#    #+#             */
/*   Updated: 2023/11/22 16:33:49 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *backup, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!backup)
	{
		backup = malloc(1 * sizeof(char));
		backup[0] = '\0';
	}
	if (!backup || !buffer)
		return (0);
	str = malloc(sizeof(char) * ((ft_strlen(backup) + ft_strlen(buffer)) + 1));
	if (!str)
		return (0);
	i = -1;
	j = 0;
	if (backup)
		while (backup[++i] != '\0')
			str[i] = backup[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[i] = '\0';
	free(backup);
	return (str);
}
