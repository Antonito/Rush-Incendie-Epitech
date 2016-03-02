/*
** palette.c for gfx_incendie in /gfx_incendie/src/my_effect
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Dec  5 07:46:45 2015 Antoine Baché
** Last update Sun Dec  6 09:50:50 2015 Antoine Baché
*/

#include "lava.h"

unsigned int	check_gradient(int i)
{
  t_color	color;

  color.full = 0;
  if (i > 0 && i <= 32)
    color.argb[0] = (i - 1) * 8;
  else if (i > 32 && i <= 64)
    {
      color.argb[0] = 255;
      color.argb[1] = (i - 1) * 8 - 255;
    }
  else if (i > 64 && i < 97)
    {
      color.argb[0] = 255;
      color.argb[1] = 255;
      color.argb[2] = (i - 1) * 8 - 255 * 2;
    }
  return (color.full);
}

void	palette_generator(unsigned int *palette)
{
  int	i;

  i = -1;
  while (++i < PALETTE_SIZE)
    {
      if (i == 0)
	palette[i] = BLACK_COLOR;
      else if (i > 96 && i <= 127)
	palette[i] = WHITE_COLOR;
      else
	palette[i] = check_gradient(i);
    }
}
