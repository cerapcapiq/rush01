/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlye-chi <hlye-chi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:23:34 by hlye-chi          #+#    #+#             */
/*   Updated: 2022/02/21 10:23:37 by hlye-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		compareclues(int board[4][4], int *in_num);

int	find0(int board[4][4], int *row, int *col)
{
	*row = 0;
	*col = 0;
	while (*row < 4)
	{
		*col = 0;
		while (*col < 4)
		{
			if (board[*row][*col] == 0)
				return (1);
			*col += 1;
		}
		*row += 1;
	}
	return (0);
}

int	validatecol(int board[4][4], int col, int num)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (board[row][col] == num)
			return (0);
		row++;
	}
	return (1);
}

int	validaterow(int board[4][4], int row, int num)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (board[row][col] == num)
			return (0);
		col++;
	}
	return (1);
}

int	validatecolrow(int board[4][4], int row, int col, int num)
{
	if (((validaterow(board, row, num)) && (validatecol(board, col, num))
			&& (board[row][col] == 0)))
		return (1);
	return (0);
}

int	bruteforce(int board[4][4], int *arg)
{
	int	row;
	int	col;
	int	n;

	n = 1;
	if ((find0(board, &row, &col) == 0) && (compareclues(board, arg) == 1))
		return (1);
	while (n <= 4)
	{
		if (validatecolrow(board, row, col, n))
		{
			board[row][col] = n;
			if (bruteforce(board, arg) == 1)
				return (1);
			board[row][col] = 0;
		}
		n++;
	}
	return (0);
}
