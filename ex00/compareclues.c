/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compareclues.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlye-chi <hlye-chi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:23:59 by hlye-chi          #+#    #+#             */
/*   Updated: 2022/02/21 10:24:03 by hlye-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col_up(int board[4][4], int col, int num)
{
	int	row;
	int	max;
	int	count;

	row = 0;
	count = 1;
	max = board[row][col];
	while (row < 4)
	{
		if (board[row][col] > max)
		{
			max = board[row][col];
			count++;
		}
		row++;
	}
	if (count == num)
		return (1);
	return (0);
}

int	check_col_down(int board[4][4], int col, int num)
{
	int	i;
	int	max;
	int	count;

	i = 3;
	count = 1;
	max = board[i][col];
	while (i >= 0)
	{
		if (board[i][col] > max)
		{
			max = board[i][col];
			count++;
		}
		i--;
	}
	if (count == num)
		return (1);
	return (0);
}

int	check_row_left(int board[4][4], int row, int num)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	count = 1;
	max = board[row][i];
	while (i < 4)
	{
		if (board[row][i] > max)
		{
			max = board[row][i];
			count++;
		}
		i++;
	}
	if (count == num)
		return (1);
	return (0);
}

int	check_row_right(int board[4][4], int row, int num)
{
	int	i;
	int	max;
	int	count;

	i = 3;
	count = 1;
	max = board[row][i];
	while (i >= 0)
	{
		if (board[row][i] > max)
		{
			max = board[row][i];
			count++;
		}
		i--;
	}
	if (count == num)
		return (1);
	return (0);
}

int	compareclues(int board[4][4], int *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (i >= 0 && i <= 3)
			if (!check_col_up(board, i, arg[i]))
				return (0);
		if (i >= 4 && i <= 7)
			if (!check_col_down(board, i - 4, arg[i]))
				return (0);
		if (i >= 8 && i <= 11)
			if (!check_row_left(board, i - 8, arg[i]))
				return (0);
		if (i >= 12 && i <= 15)
			if (!check_row_right(board, i - 12, arg[i]))
				return (0);
		i++;
	}
	return (1);
}
