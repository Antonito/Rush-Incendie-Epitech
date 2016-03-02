/*
** lines.c for gfx_incendie in /gfx_incendie/src/my_effect
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Dec  5 07:47:29 2015 Antoine Baché
** Last update Sun Dec  6 09:43:52 2015 Antoine Baché
*/

#include "lava.h"

void	random_lines(char *colors)
{
  int	i;
  int	j;

  i = WIN_X * WIN_Y - 1;
  j = WIN_X * (WIN_Y + 2);
  while (++i < j)
    colors[i] = rand() % PALETTE_SIZE;
}
