/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 00:33:21 by paubello          #+#    #+#             */
/*   Updated: 2025/02/19 06:15:40 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

# define BUFFER_SIZE 42

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			total;
	size_t			i;

	total = count * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total)
		ptr[i++] = 0;
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}


static char	*ft_process_line(char **stash, char *newline_pos)
{
	char	*line;
	char	*temp;
	size_t	len;

	len = newline_pos - *stash + 1;
	line = (char *)ft_calloc(len + 1, sizeof(char));
	if (!line)
		return (NULL);
	temp = *stash;
	while (len--)
		*line++ = *temp++;
	*line = '\0';
	line -= (newline_pos - *stash + 1);
	temp = ft_strjoin(temp, "");
	free(*stash);
	*stash = temp;
	return (line);
}

static char	*ft_extract_line(char **stash)
{
	char	*line;
	char	*newline_pos;

	if (!*stash || !**stash)
		return (NULL);
	newline_pos = ft_strchr(*stash, '\n');
	if (newline_pos)
		return (ft_process_line(stash, newline_pos));
	line = ft_strjoin(*stash, "");
	free(*stash);
	*stash = NULL;
	return (line);
}

static char	*ft_read_file(int fd, char **stash)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes_read;

	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(*stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*stash, buffer);
		free(*stash);
		*stash = temp;
	}
	free(buffer);
	return (*stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	if (!stash)
		return (NULL);
	if (!ft_read_file(fd, &stash))
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_extract_line(&stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	find_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *nbr, char *base_from)
{
	int	i;
	int	sign;
	int	result;
	int	index;

	i = 0;
	sign = 1;
	result = 0;
	index = 0;
	while (ft_isspace(nbr[i]))
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i++] == '-')
			sign *= -1;
	}
	while (nbr[i])
	{
		index = find_index(nbr[i++], base_from);
		if (index == -1)
			break ;
		result = result * ft_strlen(base_from) + index;
	}
	return (result * sign);
}

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
