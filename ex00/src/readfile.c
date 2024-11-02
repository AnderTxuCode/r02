#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int	getLineNumber(const char *file_path)
{
	int		file_descriptor;
	char	character;
	int		index;
	int		line_count;

	file_descriptor = open(file_path, O_RDONLY);
	if (file_descriptor == -1)
		return (-1);
	character = 0;
	index = 0;
	line_count = 0;
	while (read(file_descriptor, &character, 1))
	{
		if (character == '\n')
			index = -1;
		if (index == 0)
			line_count++;
		index++;
	}
	close(file_descriptor);
	return (line_count);
}

int	*getLengthOfLine(const char *file_path)
{
	int		file_descriptor;
	int		*line_lengths;

	line_lengths = malloc(sizeof(int) * (1 + getLineNumber(file_path)));
	if (line_lengths == NULL)
		return (NULL);
	line_lengths[0] = getLineNumber(file_path);
	file_descriptor = open(file_path, O_RDONLY);
	if (file_descriptor == -1 || line_lengths[0] == -1)
		return (NULL);
	if (getLineLength(file_descriptor, line_lengths) == NULL)
		return (NULL);
	close(file_descriptor);
	return (line_lengths);
}

int	getLines(const char *file_path, char ***lines_array)
{
	int			file_descriptor;
	int			*line_lengths;
	const char	*default_path = "numbers.dict";

	if (file_path == NULL)
		file_path = default_path;
	line_lengths = getLengthOfLine(file_path);
	file_descriptor = open(file_path, O_RDONLY);
	if (line_lengths == NULL || file_descriptor == -1)
		return (-1);
	*lines_array = malloc(sizeof(char *) * (line_lengths[0] + 1));
	if (*lines_array == NULL)
		return (-1);
	if (getLineLoop(file_descriptor, line_lengths, lines_array) == -1)
		return (-1);
	free(line_lengths);
	close(file_descriptor);
	return (0);
}
