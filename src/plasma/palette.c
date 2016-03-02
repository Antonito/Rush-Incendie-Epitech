/*
** palette.c for gfx_incendie in /gfx_incendie/src/plasma
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Dec  5 09:23:26 2015 Antoine Baché
** Last update Sun Dec  6 06:30:51 2015 Antoine Baché
*/

#include "plasma.h"

unsigned int	check_gradient(int i)
{
  t_color	color;

  color.full = 0;
  if (i >= 0 && i < 64)
    color.argb[0] = (i - 1) * 4;
  else if (i >= 64 && i < 128)
    {
      color.argb[0] = 255  - (i - 64) * 4;
      color.argb[1] = (i - 64) * 4;
    }
  else if (i >= 128 && i < 192)
    {
      color.argb[1] = 255 - (i - 128) * 4;
      color.argb[2] = (i - 128) * 4;
    }
  else if (i >= 192 && i < 256)
    {
      color.argb[0] = (i - 192) * 4;
      color.argb[2] = 255 - (i - 192) * 4;
    }
  return (color.full);
}

void	palette_generator(unsigned int *palette)
{
  int	i;

  i = -1;
  while (++i < PALETTE_SIZE)
    {
      palette[i] = check_gradient(i);
    }
}
