/*
** load_ini.c for gfx_incendie in /gfx_incendie/src/rotation
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Sun Dec  6 05:25:22 2015 nathan scutari
** Last update Sun Dec  6 12:17:03 2015 nathan scutari
*/

#include "rotation.h"

int		malloc_list(t_list **list, unsigned int nbr,
			    t_list **first)
{
  t_list	*elem;

  if ((elem = bunny_malloc(sizeof(*elem))) == NULL)
    return (-1);
  elem->palette = nbr;
  elem->next = *list;
  if (elem->next == NULL)
    *first = elem;
  *list = elem;
  return (0);
}

int		get_list(t_bunny_ini *ini, t_list **list,
			 const char *file_format)
{
  int		i;
  unsigned int	nbr;
  const char	*str;
  t_list	*first;

  i = -1;
  if (bunny_ini_get_field(ini, file_format, "palette", 0) == NULL)
    return (-1);
  while ((str = bunny_ini_get_field(ini, file_format,
				    "palette", ++i)) != NULL)
    {
      if (my_getnbr(str) == -1)
	return (-1);
      else
	nbr = my_getnbr(str);
      if (malloc_list(list, nbr, &first) == -1)
	return (-1);
    }
  first = *list;
  reverse_list(list);
  if (first == NULL)
    return (-1);
  first->next = *list;
  return (0);
}

int	get_win_height(t_bunny_ini *ini, char *file_format)
{
  int	height;

  if ((bunny_ini_get_field(ini, file_format, "height", 0)) == NULL)
    return (-1);
  if ((height = my_getnbr(bunny_ini_get_field(ini, file_format, "height", 0)))
       == -1)
      return (-1);
  if (height == 0)
    return (-1);
  return (height);
}

int	get_win_width(t_bunny_ini *ini, char *file_format)
{
  int	width;

  if ((bunny_ini_get_field(ini, file_format, "width", 0)) == NULL)
    return (-1);
  if ((width = my_getnbr(bunny_ini_get_field(ini, file_format, "width", 0)))
      == -1)
    return (-1);
  if (width == 0)
    return (-1);
  return (width);
}

int	get_format(char *file_name, char *file_format)
{
  int	i;
  int	j;

  i = -1;
  j = -1;
  if (file_name == NULL)
    return (-1);
  while (file_name[++i] != '/');
  while (file_name[++i] != '.' && file_name[i] != 0)
    file_format[++j] = file_name[i];
  file_format[++j] = 0;
  return (0);
}
