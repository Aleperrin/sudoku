/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_availability.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 22:11:10 by alperrin          #+#    #+#             */
/*   Updated: 2019/05/09 12:08:54 by alperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_check_availability(int sudoku[9][9], int row, int col, int num)
{
	if (( ft_check_line(sudoku[9][9], row, num) == 0) 
		|| (ft_check_column(sudoku[9][9], col, num)  == 0) 
		|| (ft_check_square (sudoku[9][9], row, col, num) == 0))
		return (0);
	else
	return (1);

}	


int	ft_check_line(int sudoku[9][9], int row, int num)
{
	int i;

	i = 0;
	while (i < 9)
	{	
	if (sudoku[row][i] == num)
		return (0);
	i = i + 1;
	}
	return (1);
}

int	ft_check_column(int sudoku[9][9], int col,  int num)
{
	int i;

	i = 0;
	while (i < 9)
	{	
	if (sudoku[i][col] == num)
		return (0);
	i = i + 1;
	}
	return (1);
}

int	ft_check_square(int sudoku[9][9], int row, int col, int num)
{
	int row_init;
	int col_init;
	int i;
	int j;

	row_init = (row / 3) * 3;
	col_init = (col / 3) * 3;
	i = row_init ;
	while (i < row_init + 3)
		{
			j = col_init;
			while (j < col_init + 3)
				{ 
					if (sudoku[i][j] == num)
							return (0);
					j = j + 1;
				}
			i = i + 1;
		}
	return (1);
}
