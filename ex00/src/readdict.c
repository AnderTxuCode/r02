#include <stdio.h>
#include <stdlib.h>

char	*duplicatedString(char *source_str, int start_index, int end_index)
{
	int		current_index;
	char	*result;

	result = (char *)malloc(sizeof(char) * (end_index - start_index + 2));
	current_index = 0;
	while (start_index <= end_index)
	{
		result[current_index] = source_str[start_index];
		start_index++;
		current_index++;
	}
	result[current_index] = 0;
	return (result);
}

int	getNumber(int *current_index, char *input_str, char **number)
{
	int	start_index;

	if (input_str[*current_index] == '+' || input_str[*current_index] == '-')
		*current_index = *current_index + 1;
	else if (input_str[*current_index] < '0' || input_str[*current_index] > '9')
		return (1);
	start_index = *current_index;
	while (input_str[*current_index] >= '0' && input_str[*current_index] <= '9')
		*current_index = *current_index + 1;
	*number = duplicatedString(input_str, start_index, *current_index - 1);
	return (0);
}

int	onlySpaces(int current_index, char *input_str)
{
	while (input_str[current_index] != 0)
	{
		if (input_str[current_index] != ' ')
			return (0);
		current_index++;
	}
	return (1);
}

int	getSize(int current_index, char *input_str)
{
	int	value_size;

	value_size = 0;
	while (input_str[current_index] >= 32 && input_str[current_index] <= 126)
	{
		if (onlySpaces(current_index, input_str) == 1)
			break ;
		if (input_str[current_index] != ' ')
			value_size++;
		else if (input_str[current_index] == ' ' && input_str[current_index - 1] != ' ' && input_str[current_index - 1] != ':')
			value_size++;
		current_index++;
	}
	return (value_size);
}
