/*
** load_colors.c for gfx_incendie in /gfx_incendie/src/rotation
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Sun Dec  6 06:37:58 2015 nathan scutari
** Last update Sun Dec  6 11:23:32 2015 Antoine Baché
*/

#include "rotation.h"

int	get_colors(t_bunny_ini *ini, int size,
		   int *colors, char *file_format)
{
  int	i;

  i = -1;
  while (++i < size)
    {
      if ((colors[i] =
	   my_getnbr(bunny_ini_get_field(ini, file_format, "picture", i)))
	  == -1)
	return (-1);
    }
  return (0);
}
