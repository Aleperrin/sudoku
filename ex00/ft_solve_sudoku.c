/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 14:53:20 by thallot           #+#    #+#             */
/*   Updated: 2019/05/15 17:11:54 by alperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_initialize_sudoku(char **argv, int tab[9][9])
{
	int line;
	int chiffre;

	line = 1;
	while (line <= 9)
	{
		chiffre = 0;
		while (argv[line][chiffre] != '\0')
		{
			if (argv[line][chiffre] == '.')
				tab[line - 1][chiffre] = 0;
			else
				tab[line - 1][chiffre] = argv[line][chiffre] - '0';
			chiffre++;
		}
		line++;
	}
}

int		ft_solve_sudoku(int sudoku[9][9], int position)
{
	int row;
	int col;
	int chiffre;

	row = position / 9;
	col = position % 9;
	chiffre = 1;
	if (position == 81)
		return (1);
	if (sudoku[row][col] != 0)
		return (ft_solve_sudoku(sudoku, position + 1));
	while (chiffre <= 9)
	{
		if (ft_check_availability(sudoku, row, col, chiffre) == 1)
		{
			sudoku[row][col] = chiffre;
			if (ft_solve_sudoku(sudoku, position + 1) == 1)
				return (1);
		}
		chiffre++;
	}
	sudoku[row][col] = 0;
	return (0);
}

int		ft_solve2_sudoku(int sudoku[9][9], int position, int tab[9][9])
{
	int row;
	int col;
	int chiffre;

	row = position / 9;
	col = position % 9;
	chiffre = 1;
	if (position == 81)
		return (1);
	if (sudoku[row][col] != 0)
		return (ft_solve_sudoku(sudoku, position + 1));
	while (chiffre <= 9)
	{
		if (ft_check_availability(sudoku, row, col, chiffre) == 1 
			&& tab[row][col] != sudoku[row][col])
		{
			sudoku[row][col] = chiffre;
			if (ft_solve_sudoku(sudoku, position + 1) == 1)
				return (1);
		}
		chiffre++;
	}
	sudoku[row][col] = 0;
	return (0);
}
