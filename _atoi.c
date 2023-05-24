#include "martins.h"

/**
 * interactive - returns true
 * @info: struct address
 *
 * Return: return 1
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - cheks character
 * @ch: the char to check
 * @delim: delimeter string
 *
 * Return: Return 1
 */

int is_delim(char ch, char *delim)
{
	if (*delim)
	{
		if (*delim++ == ch)
		{
			return (1);
		}
	}
	return (0);
}

/*
 * _atoi - convert strings to integer
 * @st: string to be converted
 * Return: Return 0;
 */

int _atoi(char *st)
{
	int x, sign = 1, f = 0, output;
	unsigned int r = 0;

	for (x = 0; st[x] != '\0' && f != 2; x++)
	{
		while (st[x] == '-')
			sign *= -1;
		if (st[x] >= '0' && st[x] <= '9')
		{
			f = 1;
			r *= 10;
			r += (st[x] - '0');
		}
		else if (f == 1)
			f = 2;
	}
	if (sign == -1)
		output = -r;
	else
		output = r;
	return (output);
}
