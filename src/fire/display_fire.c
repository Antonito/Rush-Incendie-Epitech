/*
** display_fire.c for gfx_incendie in /gfx_incendie/src
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Sat Dec  5 00:41:46 2015 nathan scutari
** Last update Sun Dec  6 09:07:14 2015 Antoine Baché
*/

#include "fire.h"

void		display_fire(t_bunny_pixelarray *pix,
			     short *colors, unsigned int *palette)
{
  int		i;
  t_color	*color;

  i = -1;
  color = pix->pixels;
  while (++i < WIN_X * WIN_Y)
    {
      if (i < WIN_Y / 2)
	color[i].full = BLACK;
      else if (colors[i] < 89)
	color[i].full = BLACK_COLOR;
      else
	color[i].full = palette[(int)colors[i]];
    }
}
