/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:58:48 by ymostows          #+#    #+#             */
/*   Updated: 2024/01/23 16:34:04 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_update_backup(char *backup)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (0);
	}
	str = malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!str)
		return (0);
	i++;
	j = 0;
	while (backup[i])
		str[j++] = backup[i++];
	str[j] = '\0';
	free(backup);
	return (str);
}

char	*ft_get_backup(int fd, char *backup)
{
	char	*buffer;
	int		rd_len;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	rd_len = 1;
	while (!ft_strchr(backup, '\n') && rd_len != 0)
	{
		rd_len = read(fd, buffer, BUFFER_SIZE);
		if (rd_len == -1)
		{
			free(buffer);
			free(backup);
			return (0);
		}
		buffer[rd_len] = '\0';
		backup = ft_strjoin(backup, buffer);
	}
	free(buffer);
	return (backup);
}

char	*ft_get_line(char *backup)
{
	int		i;
	char	*str;

	i = 0;
	if (!backup[i])
		return (0);
	while (backup[i] && backup[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (0);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		str[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		str[i] = backup[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*backup[1024];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	backup[fd] = ft_get_backup(fd, backup[fd]);
	if (!backup[fd])
		return (0);
	line = ft_get_line(backup[fd]);
	backup[fd] = ft_update_backup(backup[fd]);
	return (line);
}
int	main(int argc, char **argv)
{
	int		fd;
	char	*temp;

	printf("B:%d\n", BUFFER_SIZE);
	fd = open(argv[1], O_RDONLY);
	do
	{
		temp = get_next_line(fd);
		printf("%s", temp);
		free(temp);
	} while (temp);
}