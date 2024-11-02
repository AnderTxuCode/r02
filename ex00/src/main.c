#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

int	isNumber(char *input_string)
{
	int	index;

	index = 0;
	while (input_string[index] != '\0')
	{
		if (input_string[index] < '0' || input_string[index] > '9')
			return (-1);
		index++;
	}
	return (0);
}

char	*numberConversion(int argc, char **argv, char **dict_path)
{
	if (argc == 2)
	{
		*dict_path = NULL;
		if (isNumber(argv[1]) == 0)
			return (argv[1]);
	}
	else if (argc == 3)
	{
		*dict_path = argv[1];
		if (isNumber(argv[2]) == 0)
			return (argv[2]);
	}
	write(2, "Error\n", 6);
	return (NULL);
}

int	main(int argc, char **argv)
{
	char	*converted_string;
	char	*number_to_convert;
	char	*dictionary_path;
	int	index;

	number_to_convert = numberConversion(argc, argv, &dictionary_path);
	if (number_to_convert != NULL)
		converted_string = getInput(number_to_convert, dictionary_path);
	index = 1;
	while (converted_string[index] != '\0')
	{
		write(1, &converted_string[index], 1);
		index++;
	}
	free(converted_string);
	return (0);
}
