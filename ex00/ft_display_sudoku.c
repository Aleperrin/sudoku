/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_sudoku.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 16:20:27 by thallot           #+#    #+#             */
/*   Updated: 2019/05/09 12:07:52 by alperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_show(int tab[9][9])
{
	int line;
	int chiffre;

	line = 0;
	chiffre = 0;
	while (line < 9)
	{
		chiffre = 0;
		while (chiffre < 9)
		{
			ft_putchar(tab[line][chiffre] + '0');
			if (chiffre < 8)
				ft_putchar(' ');
			chiffre++;
		}
		ft_putchar('\n');
		line++;
	}
}
