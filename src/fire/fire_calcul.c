/*
** fire_calcul.c for gfx_incendie in /gfx_incendie/src
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Fri Dec  4 22:35:19 2015 nathan scutari
** Last update Sun Dec  6 19:04:27 2015 Antoine Baché
*/

#include "fire.h"

int	pos_average(int i, short *colors, int mod)
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
  p_r = colors[i + WIN_X + 1];
  p_u = colors[i + 2 * WIN_X];
  average = (p + p_l + p_r + p_u) / 4;
  if (average > 70 && average < 120 && rand() % 100 > 95)
    average -= 11;
  if (average < 64)
    average -= 10;
  average = intensity_mod(average, mod);
  return (average);
}

int	intensity_mod(int average, int mod)
{
  if (rand() % 100 > 95)
    average += mod;
  if (average >= 90 && rand() % 100 >  97)
    average -= 15;
  if (average < 0)
    average = 0;
  return (average);
}

int	first_pos_average(int i, short *colors)
{
  int	average;

  average = (colors[i + WIN_X] + colors[i + WIN_X * 2] +
	     colors[i + WIN_X + 1]) / 3;
  return (average);
}

int	last_pos_average(int i, short *colors)
{
  int	average;

  average = (colors[i + WIN_X] + colors[i + WIN_X * 2] +
	      colors[i + WIN_X - 1])/ 3;
  return (average);
}

void	fire_calculator(short *colors, int mod)
{
  int	i;
  int	average;

  i = WIN_X * WIN_Y;
  while (--i >= 0)
    {
      if (i % WIN_X == WIN_X - 1)
	average = last_pos_average(i, colors);
      else if (i % WIN_X == 0)
	average = first_pos_average(i, colors);
      else
	average = pos_average(i, colors, mod);
      colors[i] = average;
    }
}
