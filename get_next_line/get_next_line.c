/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:01:52 by marvin            #+#    #+#             */
/*   Updated: 2023/11/20 21:24:14 by marvin           ###   ########.fr       */
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
	static char		*backup;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	backup = ft_get_backup(fd, backup);
	if (!backup)
		return (0);
	line = ft_get_line(backup);
	backup = ft_update_backup(backup);
	return (line);
}

int main(int argc, char const *argv[])
{
    char *line;
    int i;
    int n;
    int  fd;
    if (argc == 3)
    {
        fd = open(argv[1], O_RDONLY); 
        if (fd == -1)
            return (0);
        n = atoi(argv[2]);
        i = 0;
        while (i < n)
        {
            line = get_next_line(fd);
            if (!line)
                return (0);
			if (i < n-1)
				free(line);
            i++;
        }
		printf("line : %s",line);
        close(fd);
    }
    return 0;
}
