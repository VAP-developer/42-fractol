/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:31:42 by vicalons          #+#    #+#             */
/*   Updated: 2024/11/05 12:53:04 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* FUNC SURPLUS_LINE
 * 	save char after \n in surplus
 * VAR
 * 	i
 * 	j
 * 	surplus
 * CODE
 * 	1. find \n
 * 	2. if dont find \n --> free & return
 * 	3. surplus = \n...
 * RETURN
 * 	surplus
 * EXAMPLE
 * 	surplus_line("hello\nworld") --> "world"
 */
char	*surplus_line(char *next_line)
{
	int		i;
	int		j;
	char	*surplus;

	i = 0;
	j = 0;
	while (next_line[i] && next_line[i] != '\n')
		i++;
	if (!next_line[i])
	{
		free(next_line);
		return (NULL);
	}
	surplus = ft_calloc((ft_strlen(next_line) - i + 1), sizeof(*next_line));
	if (!surplus)
		return (NULL);
	i++;
	while (next_line[i])
		surplus[j++] = next_line[i++];
	surplus[j] = '\0';
	free(next_line);
	return (surplus);
}

/* FUNC CLEAR_LINE
 * 	clear a line with \n, save all before the first \n
 * VAR
 * 	i:   (size_t) is an iterate
 * 	new:   (char) is a new clean str
 * CODE
 * 	1. Test next_line
 * 	2. Find \n or \0
 * 	3. Copy in new the str until \n or \0
 * 	4. add \n (to write it)
 * RETURN
 * 	new
 * EXAMPLE
 *	clean_line("hello") --> "hello\n"
 *	clean_line("hello\nworld") --> "hello\n"
 */
char	*clear_line(char *next_line)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!next_line[i])
		return (NULL);
	while (next_line[i] && next_line[i] != '\n')
		i++;
	new = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (next_line[i] && next_line[i] != '\n')
	{
		new[i] = next_line[i];
		i++;
	}
	new[i++] = '\n';
	return (new);
}

/* FUNC: STRJOIN & FREE
 * 	join two str and free old str
 * VAR
 * 	tmp: (char) save new str
 * CODE
 * 	1. tmp = strjoin
 * 	2. free(old)
 * RETURN
 * 	tmp
 * EXAMPLE
 * 	******************
 */
char	*ft_join_and_free(char *next_line, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(next_line, buffer);
	free(next_line);
	return (tmp);
}

/* FUNC: READ_LINE
 * 	it read text until it find '\n'
 * VAR
 * 	buffer: (char) store the text
 * 	bytes:  (int) number of bytes read
 * CODE
 * 	1. buffer malloc(BUFFER_SIZE)
 * 	2. Read(fd, buffer, BUFFER_SIZE)
 * 	3. Test read
 * 		bytes == -1 -> free (all)
 * 		bytes != -1 -> continue
 * 	4. next_line = strjoin & free
 * 	5. test \n
 * 		if \n is next_line -> end
 * 		if \n isnt next_line -> step 2
 * RETURN
 * 	next_line
 * EXAMPLE
 * 	TEXT: "hello wordl\nits a new day"
 * 	BS: 7
 * 	next_line: "\0"
 * 	Process: "hello w","ordl\nit"
 * 	read_line --> "hello world\nit"
 */
char	*read_line(int fd, char *next_line)
{
	char	*buffer;
	int		bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(next_line);
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		next_line = ft_join_and_free(next_line, buffer);
		if (ft_strchr(next_line, '\n'))
			break ;
	}
	free (buffer);
	return (next_line);
}

/* FUNC GNL
 * 	read a line of a text
 * VAR
 * 	line:      (char) read line
 * 	next_line: (static char) surplus line
 * CODE
 * 	1. TEST 1: fd and BUFFER_SIZE
 * 		fd < 0 if is a error when we open text.txt
 * 		BUFFER_SIZE < 1 we cant read the fd
 * 	2. TEST 2: odds next_line
 * 		A: next_line = NULL -> ft_calloc
 * 		B: next_line = "hello\nworld" -> clear
 * 		C: next_line = "hello" -> step 3
 * 	3. Read the text
 */
char	*get_next_line(int fd)
{
	char		*line;
	static char	*next_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!next_line)
		next_line = ft_calloc(1, 1);
	else
	{
		if (ft_strchr(next_line, '\n'))
		{
			line = clear_line(next_line);
			next_line = surplus_line(next_line);
			return (line);
		}
	}
	next_line = read_line(fd, next_line);
	if (!next_line)
		return (NULL);
	line = clear_line(next_line);
	next_line = surplus_line(next_line);
	return (line);
}
