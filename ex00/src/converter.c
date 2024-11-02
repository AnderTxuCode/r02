#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

int	print_num(char *input_str, int print_option, char *output_string);

char	**g_number_array;
char	**g_value_array;

int	printLess100(char *input_str, int print_option, char *output_string)
{
	char	*copied_string;
	int		number;
	int		total_sum;

	number = myAtoi(input_str);
	if (number <= 20 || number % 10 == 0)
	{
		if (print_option)
			myStrcatSpaces(output_string, getValues(input_str, g_number_array, g_value_array));
		return (myStrlen(getValues(input_str, g_number_array, g_value_array)) + 1);
	}
	else if (number <= 100)
	{
		total_sum = 0;
		copied_string = myStringDuplicate(input_str);
		copied_string[1] = '0';
		total_sum += print_num(copied_string, print_option, output_string);
		total_sum += print_num(input_str + 1, print_option, output_string);
		free(copied_string);
		return (total_sum);
	}
	return (0);
}

int	printSup100(char *input_str, int print_option, char *output_string)
{
	int		total_sum;
	char	*magnitude_string;
	char	*remaining_values;

	total_sum = 0;
	magnitude_string = getLengthNumber(input_str);
	total_sum += print_num(magnitude_string, print_option, output_string);
	remaining_values = getValues(getLength(input_str), g_number_array, g_value_array);
	if (print_option)
		myStrcatSpaces(output_string, remaining_values);
	total_sum += print_num(input_str + myStrlen(magnitude_string), print_option, output_string);
	total_sum += myStrlen(remaining_values) + 1;
	return (total_sum);
}

int	print_num(char *input_str, int print_option, char *output_string)
{
	int		length;

	while (input_str[0] == '0')
		input_str++;
	if (input_str[0] == 0)
		return (0);
	length = myStrlen(input_str);
	if (length <= 2)
		return (printLess100(input_str, print_option, output_string));
	else
		return (printSup100(input_str, print_option, output_string));
	return (0);
}

char	*getInput(char *input_str, const char *dictionary_path)
{
	char	*output_string;
	int		output_size;
	int		current_index;
	char	**dictionary_content;

	if (getLines(dictionary_path, &dictionary_content) != 0
		|| parseString(dictionary_content, &g_number_array, &g_value_array) != 0)
	{
		write(2, "Dict Error\n", 11);
		exit(EXIT_FAILURE);
		return (0);
	}
	current_index = 0;
	if (zero(input_str) == 0)
		output_size = myStrlen(getValues("0", g_number_array, g_value_array));
	else
		output_size = print_num(input_str, 0, "");
	output_string = malloc(sizeof(char) * (output_size + 1));
	current_index = -1;
	while (current_index++ < output_size)
		output_string[current_index] = 0;
	if (zero(input_str) == 0)
		myStrcatSpaces(output_string, getValues("0", g_number_array, g_value_array));
	else
		print_num(input_str, 1, output_string);
	return (output_string);
}