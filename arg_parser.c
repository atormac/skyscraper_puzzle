
int	validate_args(char *args)
{
	int		counter;
	int		space_counter;
	char	*p;

	p = args;
	counter = 0;
	space_counter = 0;
	while (*args)
	{
		if (*args >= '1' && *args <= '4')
		{
			if (args - p > 0 && *(args - 1) != ' ')
				return (0);
			counter++;
		}
		else if (*args == ' ')
			space_counter++;
		else
			return (0);
		args++;
	}
	if (counter != 16 || space_counter != 15)
		return (0);
	return (1);
}

int	parse_arguments(char *args, int **clues)
{
	int		i;
	int		row;

	i = 0;
	row = 0;
	while (*args)
	{
		if (*args >= '1' && *args <= '4')
		{
			if (i >= 4)
			{
				i = 0;
				row++;
			}
			clues[row][i] = *args - '0';
			i++;
		}
		else if (*args != ' ')
			return (0);
		args++;
	}
	return (1);
}
