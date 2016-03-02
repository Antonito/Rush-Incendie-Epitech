/*
** calculus.c for gfx_incendie in /gfx_incendie/src/my_effect
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Dec  5 07:45:24 2015 Antoine Baché
** Last update Sun Dec  6 09:43:34 2015 Antoine Baché
*/

#include "lava.h"

int	pos_average(int i, char *colors)
{
  int	average;
  int	p_l;
  int	p_r;
  int	p_u;
  int	p;

  p = colors[i + WIN_X];
  if (i > WIN_X)
    p_l = colors[i - WIN_X];
  else
    p_l = BLACK_COLOR;
  p_r = colors[i + 1];
  p_u = colors[i + 2 * WIN_X];
  average = (p + p_l + p_r + p_u + colors[i - 1]) / 4;
  return (average);
}

int	first_pos_average(int i, char *colors)
{
  int	average;

  average = (colors[i + WIN_X] + colors[i + WIN_X * 2] +
	     colors[i + WIN_X + 1]) / 3;
  return (average);
}

int	last_pos_average(int i, char *colors)
{
  int	average;

  average = (colors[i + WIN_X] + colors[i + WIN_X * 2] +
	     colors[i + WIN_X - 1]) / 3;
  return (average);
}

void	fx_calculator(char *colors)
{
  int	i;
  int	average;

  i = -1;
  while (++i < WIN_X * WIN_Y)
    {
      if (i % WIN_X == WIN_X - 1)
	average = last_pos_average(i, colors);
      else if (i % WIN_X == 0)
	average = first_pos_average(i, colors);
      else
	average = pos_average(i, colors);
      colors[i] = average;
    }
}
