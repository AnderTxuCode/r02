#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "utils.h"

int	lineStart(int *current_index, char *input_string, char **number)
{
	*current_index = 0;
	if (getNumber(current_index, input_string, number) != 0)
		return (1);
	while (input_string[*current_index] == ' ')
		*current_index = *current_index + 1;
	if (input_string[*current_index] != ':')
		return (1);
	*current_index = *current_index + 1;
	while (input_string[*current_index] == ' ')
		*current_index = *current_index + 1;
	return (0);
}

int	parseLine(char *input_string, char **number, char **value)
{
	int	current_index;
	int	value_index;

	if (lineStart(&current_index, input_string, number) != 0)
		return (1);
	*value = (char *)malloc(sizeof(char) * (getSize(current_index, input_string) + 2));
	value_index = 0;
	while (input_string[current_index] >= 32 && input_string[current_index] <= 126)
	{
		if (onlySpaces(current_index, input_string) == 1)
			break ;
		if (input_string[current_index] != ' ' || (input_string[current_index] == ' ' && input_string[current_index - 1] != ' '))
		{
			(*value)[value_index] = input_string[current_index];
			value_index++;
		}
		current_index++;
	}
	(*value)[value_index] = 0;
	return (0);
}

int	parseString(char **input_strings, char ***numbers, char ***values)
{
	int	current_index;

	current_index = 0;
	while (input_strings[current_index] != 0)
		current_index++;
	*numbers = (char **)malloc(sizeof(char *) * (current_index + 1));
	*values = (char **)malloc(sizeof(char *) * (current_index + 1));
	current_index = 0;
	while (input_strings[current_index] != 0)
	{
		if (parseLine(input_strings[current_index], &(*numbers)[current_index], &(*values)[current_index]) != 0)
		{
			write(2, "Dict Error\n", 11);
			return (1);
		}
		current_index++;
	}
	(*numbers)[current_index] = 0;
	(*values)[current_index] = 0;
	return (0);
}