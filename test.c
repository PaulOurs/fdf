/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paubello <paubello@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 00:33:21 by paubello          #+#    #+#             */
/*   Updated: 2025/02/20 03:16:43 by paubello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

#define BUFFER_SIZE 42

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size != 0)
	{
		i = 0;
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}


static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	count_words(char const *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (count);
}

static char	*copy_word(char const *start, char const *end)
{
	char	*word;

	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, start, end - start + 1);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int			i;
	char		**result;
	char const	*start;

	i = 0;
	result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			result[i++] = copy_word(start, s);
			if (!result[i - 1])
				return (free_split(result), NULL);
		}
		else
			s++;
	}
	result[i] = (NULL);
	return (result);
}

void *ft_calloc(size_t count, size_t size)
{
	unsigned char *ptr;
	size_t total;
	size_t i;

	total = count * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total)
		ptr[i++] = 0;
	return (ptr);
}

char *ft_strchr(const char *s, int c)
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

char *ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	int i;
	int j;

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

static char *ft_process_line(char **stash, char *newline_pos)
{
	char *line;
	char *temp;
	size_t len;

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

static char *ft_extract_line(char **stash)
{
	char *line;
	char *newline_pos;

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

static char *ft_read_file(int fd, char **stash)
{
	char *buffer;
	char *temp;
	ssize_t bytes_read;

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

char *get_next_line(int fd)
{
	static char *stash;
	char *line;

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

int ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int find_index(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int ft_atoi_base(char *nbr, char *base_from)
{
	int i;
	int sign;
	int result;
	int index;

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
			break;
		result = result * ft_strlen(base_from) + index;
	}
	return (result * sign);
}

void free_tokens(char **tokens)
{
    int i = 0;
    while (tokens[i])
        free(tokens[i++]);
    free(tokens);
}

void ft_free_map(t_map *map)
{
	int i;

	if (!map || !map->map)
		return ;
	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}

int get_color(char *token)
{
	char	*comma;

	comma = ft_strchr(token, ',');
	if (comma)
		return (ft_atoi_base(comma + 1, "0123456789ABCDEF"));
	return (0xFFFFFF);
}

t_point3D parse_point(char *token, int x, int y)
{
	t_point3D point;

	point.x = x;
	point.y = y;
	point.z = ft_atoi_base(token, "0123456789");
	point.color = get_color(token);
	return (point);
}

int    ft_count_words(char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

t_map *parse_map(char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
        return NULL;

    t_map *map = malloc(sizeof(t_map));
    if (!map)
        return NULL;

    char *line;
    char **tokens;
    int y = 0;

    map->height = 0;
    map->width = 0;

    // First pass: Determine map dimensions
    while ((line = get_next_line(fd)))
    {
        if (map->width == 0)
            map->width = ft_count_words(line, ' ');

        map->height++;
        free(line);
    }
    close(fd);

    // Allocate memory for points
    map->map = malloc(sizeof(t_point3D *) * map->height);
    for (int i = 0; i < map->height; i++)
        map->map[i] = malloc(sizeof(t_point3D) * map->width);

    // Second pass: Read & store points
    fd = open(filename, O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        tokens = ft_split(line, ' '); // Split the line into tokens
        for (int x = 0; x < map->width; x++)
            map->map[y][x] = parse_point(tokens[x], x, y);

        free(line);
        free_tokens(tokens);
        y++;
    }
    close(fd);
    return map;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <map.fdf>\n", argv[0]);
        return (1);
    }

    t_map *map = parse_map(argv[1]);
    if (!map)
    {
        printf("Error: Failed to load map.\n");
        return (1);
    }

    // Print parsed map data
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
            printf("(%d, %d, %d, %#08X) ", map->map[y][x].x, map->map[y][x].y, map->map[y][x].z, map->map[y][x].color);
        printf("\n");
    }

    ft_free_map(map);
    return (0);
}

