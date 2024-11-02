#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

char	*getValues(char *search_key, char **number_array, char **value_array)
{
	int	i;
	char *empty_string;

	i = 0;
	while (number_array[i])
	{
		if (myStringcmp(number_array[i], search_key) == 0)
			return (value_array[i]);
		i++;
	}
	write(2, "Dict Error\n", 11);
	exit(EXIT_FAILURE);
	empty_string = (char *)malloc(1 * sizeof(char));
	empty_string[0] = 0;
	return (empty_string);
}

char	*getLength(char *input_string)
{
	int		n;
	int		len;
	char	*magnitude_value;

	n = myStrlen(input_string);
	len = myStrlen(input_string);
	if (len >= 4)
		while ((n - 1) % 3 != 0)
			n--;
	else
		n = len;
	magnitude_value = malloc(n + 1);
	magnitude_value[0] = '1';
	magnitude_value[n] = '\0';
	while (--n > 0)
		magnitude_value[n] = '0';
	return (magnitude_value);
}

char	*getLengthNumber(char *input_string)
{
	int		n;
	int		i;
	int		len;
	char	*number_string;

	len = myStrlen(input_string);
	if (len >= 4)
	{
		n = (myStrlen(input_string) - 1) % 3 + 1;
		number_string = malloc(n + 1);
		i = 0;
		while (i < n)
		{
			number_string[i] = input_string[i];
			i++;
		}
	}
	if (len <= 3)
	{
		n = 2;
		number_string = malloc(n);
		number_string[0] = input_string[0];
	}
	number_string[n] = '\0';
	return (number_string);
}

int	zero(char *input_string)
{
	int	current_index;

	current_index = -1;
	while (current_index++, input_string[current_index] != 0)
		if (input_string[current_index] != '0')
			return (1);
	return (0);
}