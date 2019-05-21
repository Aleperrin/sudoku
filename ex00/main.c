/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 14:53:20 by thallot           #+#    #+#             */
/*   Updated: 2019/02/17 22:42:15 by alperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_show(int tab[9][9]);
void	ft_initialize_sudoku(char **argv, int tab[9][9]);
int		ft_check_availability(int sudoku[9][9], int row, int col, int num);
int		ft_solve_sudoku(int sudoku[9][9], int position);
int		sum_sudoku(int tab[9][9]);
int		ft_solve2_sudoku(int sudoku[9][9], int position, int tab[9][9]);

int		ft_tester_arg(char **argv, int ligne)
{
	int		chiffre;
	char	c;

	chiffre = 0;
	while (argv[ligne][chiffre] != '\0')
	{
		c = argv[ligne][chiffre];
		if (((c >= '0' && c <= '9') || c == '.') && chiffre < 9)
			chiffre++;
		else
		{
			ft_putstr("Error\n");
			return (0);
		}
	}
	if (chiffre != 9)
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}

int		ft_init_main(int argc, char **argv)
{
	int	ligne;
	int	i;

	i = 1;
	ligne = 1;
	if (argc == 10)
	{
		while (ligne < 10)
		{
			i = ft_tester_arg(argv, ligne);
			if (i == 0)
				return (0);
			ligne++;
		}
		return (1);
	}
	ft_putstr("Error\n");
	return (0);
}

int		sum_sudoku(int tab[9][9])
{
	int i;
	int j;
	int res;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			res = res + tab[i][j];
			j = j + 1;
		}
		i = i + 1;
	}
	return (res);
}

int		main(int argc, char **argv)
{
	int i;
	int tab[9][9];
//	int tab2[9][9];

	i = ft_init_main(argc, argv);
	if (i == 1)
	{
		ft_initialize_sudoku(argv, tab);
		i = ft_solve_sudoku(tab, 0);
		
		if ((i == 1) && (sum_sudoku(tab) == 405))
		{
			ft_show(tab);
		}
		else
			ft_putstr("Error\n");
	}
	return (0);
}
