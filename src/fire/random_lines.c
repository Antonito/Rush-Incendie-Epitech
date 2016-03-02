/*
** random_lines.c for gfx_incendie in /gfx_incendie/fire/src
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Fri Dec  4 21:21:49 2015 nathan scutari
** Last update Sun Dec  6 09:06:57 2015 Antoine Baché
*/

#include "fire.h"

void	random_lines(short *colors)
{
  int	i;
  int	j;

  i = WIN_X * WIN_Y - 1;
  j = WIN_X * (WIN_Y + 2);
  while (++i < j)
    colors[i] = 50 + (rand() % PALETTE_SIZE - 50);
}
