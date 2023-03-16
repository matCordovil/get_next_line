/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-alm <made-alm@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:05:28 by made-alm          #+#    #+#             */
/*   Updated: 2023/03/16 13:05:31 by made-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_surplus(char *bigbuff)
{
	char	*surplus;

	return (surplus);
}

static char	*get_line(char *bigbuff)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	if (!bigbuff)
		return (NULL);
	while (bigbuff[i] && bigbuff[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (j <= i)
		line[j++] = bigbuff[j++];
	line[i++] = '\0';
	return (line);
}

static char	*get_bigbuff(int fd, char *bigbuff)
{
	
	return (bigbuff);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*bigbuff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bigbuff = get_bigbuff(fd, bigbuff);
	if (!bigbuff)
		return (NULL);
	line = get_line(bigbuff);
	bigbuff = get_surplus(bigbuff);
	return (line);
}
