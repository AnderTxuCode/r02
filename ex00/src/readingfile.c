#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	*getLineLength(int file_descriptor, int *line_sizes)
{
	char	character;
	int		index;
	int		line_count;

	character = 0;
	index = 0;
	line_count = -1;
	while (read(file_descriptor, &character, 1))
	{
		if (character == '\n')
		{
			if (index >= 0 && line_count >= 0)
				line_sizes[line_count + 1] = index;
			index = -1;
		}
		if (index == 0)
			line_count++;
		index++;
	}
	return (line_sizes);
}

int	getLinesCh(char character, int *current_indices[2], int *line_sizes, char ***lines_array)
{
	if (character == '\n')
	{
		if (*current_indices[0] >= 0)
			(*lines_array)[*current_indices[1]][*current_indices[0]] = 0;
		*current_indices[0] = -1;
	}
	if (*current_indices[0] == 0)
	{
		(*current_indices[1])++;
		(*lines_array)[*current_indices[1]] = malloc(sizeof(char)
				* (line_sizes[*current_indices[1] + 1] + 1));
		if ((*lines_array)[*current_indices[1]] == NULL)
			return (-1);
	}
	if (*current_indices[0] >= 0)
		(*lines_array)[*current_indices[1]][*current_indices[0]] = character;
	(*current_indices[0])++;
	return (0);
}

int	getLineLoop(int file_descriptor, int *line_sizes, char ***lines_array)
{
	char	character;
	int		index;
	int		line_count;
	int		read_result;
	int		*indices[2];

	character = 0;
	index = 0;
	line_count = -1;
	while (read(file_descriptor, &character, 1))
	{
		indices[0] = &index;
		indices[1] = &line_count;
		read_result = getLinesCh(character, indices, line_sizes, lines_array);
		if (read_result == -1)
			return (-1);
	}
	(*lines_array)[line_count + 1] = NULL;
	return (0);
}
