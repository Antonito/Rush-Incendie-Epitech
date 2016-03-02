/*
** display_plasma.c for gfx_incendie in /gfx_incendie/src/plasma
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Dec  5 19:30:02 2015 Antoine Baché
** Last update Sun Dec  6 06:24:01 2015 Antoine Baché
*/

#include "plasma.h"

void	display_plasma(t_bunny_pixelarray *pix,
		       short *colors, unsigned int *palette)
{
  int		i;
  t_color	*color;

  i = -1;
  color = pix->pixels;
  while (++i < WIN_X * WIN_Y - 1)
    color[i].full = palette[(unsigned int)colors[i]];
}
