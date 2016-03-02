/*
** display.c for gfx_incendie in /gfx_incendie/src/my_effect
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Dec  5 07:44:57 2015 Antoine Baché
** Last update Sun Dec  6 13:29:17 2015 nathan scutari
*/

#include "lava.h"

void		display_lava(t_bunny_pixelarray *pix,
		 char *colors, unsigned int *palette)
{
  int		i;
  int		j;
  t_color	*color;

  i = -1;
  j = WIN_X * WIN_Y - 1;
  color = pix->pixels;
  while (++i < WIN_X * WIN_Y)
    {
      if (i < WIN_Y / 2)
	color[i].full = BLACK;
      else
	color[i].full = palette[(int)colors[j]];
      --j;
    }
}
