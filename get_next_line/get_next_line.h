/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:10:18 by ymostows          #+#    #+#             */
/*   Updated: 2023/11/22 16:55:56 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *backup, char *buffer);
char	*get_next_line(int fd);

#endif
