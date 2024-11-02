#include <stdlib.h>

int	myStrlen(char *input_string)
{
	int	index;

	index = 0;
	while (input_string[index] != 0)
		index++;
	return (index);
}

void	myStrcatSpaces(char *destination, char *source)
{
	int	index;
	int	dest_index;

	index = 0;
	dest_index = myStrlen(destination);
	destination[dest_index] = ' ';
	dest_index++;
	while (source[index] != 0)
	{
		destination[dest_index] = source[index];
		index++;
		dest_index++;
	}
	destination[dest_index] = 0;
}

char	*myStringDuplicate(char *source)
{
	char	*duplicate;
	int		index;

	duplicate = (char *)malloc(myStrlen(source) + 1);
	index = 0;
	while (source[index] != 0)
		duplicate[index] = source[index], index++;
	duplicate[index] = 0;
	return (duplicate);
}

int	myStringcmp(char *string1, char *string2)
{
	int	index;

	index = 0;
	while (string1[index] != 0 && string2[index] != 0)
	{
		if (string1[index] != string2[index])
		{
			return ((unsigned char)string1[index] - (unsigned char)string2[index]);
		}
		index++;
	}
	return ((unsigned char)string1[index] - (unsigned char)string2[index]);
}

int	myAtoi(char *input_string)
{
	int	number;
	int	index;
	int	is_negative;

	index = 0;
	number = 0;
	is_negative = 1;
	while ((input_string[index] >= 9 && input_string[index] <= 13) || input_string[index] == ' ')
		index++;
	while (input_string[index] == '+' || input_string[index] == '-')
	{
		if (input_string[index] == '-')
			is_negative *= -1;
		index++;
	}
	while (input_string[index] >= 48 && input_string[index] <= 57)
	{
		number = number * 10 + input_string[index] - '0';
		index++;
	}
	return (number * is_negative);
}
