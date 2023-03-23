/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-alm <made-alm@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:05:28 by made-alm          #+#    #+#             */
/*   Updated: 2023/03/23 14:31:50 by made-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_surplus(char *bigbuff)
{
	char	*surplus;
	size_t	i;
	size_t	j;

	i = 0;
	while (bigbuff[i] != '\n' && bigbuff[i])
		i++;
	if (!bigbuff[i])
	{
		free(bigbuff);
		return (NULL);
	}
	i++;
	surplus = (char *)malloc(sizeof(char) * ((ft_strlen(bigbuff) - i) + 2));
	if (!surplus)
		return (NULL);
	j = 0;
	while (bigbuff[i])
		surplus[j++] = bigbuff[i++];
	surplus[j] = '\0';
	free(bigbuff);
	return (surplus);
}

static char	*get_line(char *bigbuff)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!bigbuff[i])
		return (NULL);
	while (bigbuff[i] && bigbuff[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	while (j <= i)
	{
		line[j] = bigbuff[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*ft_strjoin_free(char *bigbuff, char *buffer)
{
	char	*nstr;
	size_t	nlen;
	size_t	i;
	size_t	j;

	if (!bigbuff || !buffer)
		return (NULL);
	nlen = ft_strlen(bigbuff) + ft_strlen(buffer);
	nstr = (char *)malloc(sizeof(char) * (nlen + 1));
	if (!nstr)
		return (NULL);
	i = 0;
	j = 0;
	while (j < ft_strlen(bigbuff))
		nstr[i++] = bigbuff[j++];
	j = 0;
	while (j < ft_strlen(buffer))
		nstr[i++] = buffer[j++];
	nstr[i] = '\0';
	free(bigbuff);
	return (nstr);
}

static char	*get_bigbuff(int fd, char *bigbuff)
{
	char	*buffer;
	int		rd;

	if (bigbuff == NULL)
		bigbuff = ft_calloc(1, sizeof(char));
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0 || (rd == 0 && bigbuff == NULL))
		{
			free(bigbuff);
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		bigbuff = ft_strjoin_free(bigbuff, buffer);
		if (ft_strchr(bigbuff, '\n') == 1)
			break ;
	}
	free(buffer);
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
