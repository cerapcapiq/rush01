/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlye-chi <hlye-chi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:26:20 by hlye-chi          #+#    #+#             */
/*   Updated: 2022/02/21 10:26:22 by hlye-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		createbrd(int *clues);

int	checkclues4_1(char *arg)
{
	int	i;
	int	clues;

	i = 0;
	clues = 0;
	while (arg[i])
	{
		if (arg[i] == '4')
			clues++;
		i++;
	}
	if (clues > 2)
		return (0);
	i = 0;
	clues = 0;
	while (arg[i])
	{
		if (arg[i] == '1')
			clues++;
		i++;
	}
	if (clues != 4)
		return (0);
	return (1);
}

int	checkclues(char *arg, int *clues)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (checkclues4_1(arg) == 1)
	{
		while (arg[i])
		{
			if ((arg[i] >= '1' && arg[i] <= '4') && ((arg[i + 1] == ' ')
					|| ((arg[i + 1] == 0) && (arg[i - 1] == ' '))))
			{
				clues[cnt] = (arg[i] - '0');
				cnt++;
				i++;
			}
			if ((arg[i] >= 9 && arg[i] <= 13) || arg[i] == 32)
				i++;
			else
				return (cnt);
		}
		clues[cnt] = '\0';
		return (cnt);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	clues[16];

	if (argc == 2)
	{
		if (checkclues(argv[1], clues) == 16)
			createbrd(clues);
		else
			write(1, "\nERROR\n\n", 8);
	}
	else
		write(1, "\nERROR - One argument is allowed\n\n", 33);
	return (0);
}
