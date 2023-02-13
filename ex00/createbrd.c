/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createbrd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlye-chi <hlye-chi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:24:11 by hlye-chi          #+#    #+#             */
/*   Updated: 2022/02/21 10:34:06 by hlye-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		bruteforce(int board[4][4], int *arg);

void	outputres(int board[4][4]);

void	checkclue4_2_3(int board[4][4], int *arg, int i)
{
	int	j;

	j = 0;
	while ((arg[i]) && i <= 15)
	{
		if ((arg[i] == 4) && ((i >= 8 && i <= 11)))
		{
			while (j < 4)
			{
				board[i % 4][j] = j + 1;
				j++;
			}
		}
		j = 4;
		if ((arg[i] == 4) && ((i >= 12 && i <= 15)))
		{
			while (j > 0)
			{
				board[i % 4][4 - j] = j;
				j--;
			}
		}
		i++;
	}
}

void	checkclue4_0_1(int board[4][4], int *arg)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while ((arg[i]) && i < 8)
	{
		if ((arg[i] == 4) && ((i >= 0 && i <= 3)))
		{
			while (++j < 4)
			{
				board[j][i] = j + 1;
			}
		}
		j = 5;
		if ((arg[i] == 4) && ((i >= 4 && i <= 7)))
		{
			while (--j > 0)
			{
				board[4 - j][(i % 4)] = j;
			}
		}
		i++;
	}
	checkclue4_2_3(board, arg, i);
}

void	checkclue1(int board[4][4], int *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{	
		if ((arg[i] == 1) && ((i >= 0) && (i <= 3)))
			board[0][i] = 4;
		if ((arg[i] == 1) && ((i >= 4) && (i <= 7)))
			board[3][i - 4] = 4;
		if ((arg[i] == 1) && ((i >= 8) && (i <= 11)))
			board[i - 8][0] = 4;
		if ((arg[i] == 1) && ((i >= 12) && (i <= 15)))
			board[i - 12][3] = 4;
		i++;
	}
	checkclue4_0_1(board, arg);
}

int	createbrd(int *arg)
{
	int		row;
	int		col;
	int		board[4][4];

	row = 0;
	col = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			board[row][col] = 0;
			col++;
		}
		row++;
	}
	checkclue1(board, arg);
	if ((bruteforce(board, arg)) == 1)
		outputres(board);
	else
		write(1, "\nERR - No Solution\n\n", 20);
	return (0);
}
