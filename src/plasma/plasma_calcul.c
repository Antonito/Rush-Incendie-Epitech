/*
** plasma_calcul.c for gfx_incendie in /gfx_incendie/src/plasma
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Dec  5 19:13:06 2015 Antoine Baché
** Last update Sun Dec  6 07:16:06 2015 Antoine Baché
*/

#include "plasma.h"

double		pos_calc(int i, int j, unsigned char zoom)
{
  double	value;

  value = (cos((i * M_PI / 180) / zoom)) *
    (sin((j * M_PI / 180) / zoom)) * PALETTE_SIZE;
  return (ABS(value));
}

void	plasma_calculator(short *colors, unsigned char zoom, unsigned char mod)
{
  int	i;
  int	j;

  j = -1;
  i = -1;
  while (++j < WIN_Y)
    {
      i = -1;
      while (++i < WIN_X)
	{
	  colors[i + WIN_X * j] = (int)(pos_calc(i - 2 * mod, j + 2 * mod, zoom)
					+ mod) % PALETTE_SIZE;
	}
    }
}
