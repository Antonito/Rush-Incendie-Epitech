/*
** free_elems.c for gfx_incendie in /gfx_incendie/src/rotation
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Sun Dec  6 09:36:25 2015 nathan scutari
** Last update Sun Dec  6 11:09:50 2015 Antoine Baché
*/

#include "rotation.h"

void		free_elems(t_prog *prog, t_bunny_ini *ini)
{
  t_list	*tmp;
  int		i;
  int		j;

  i = 0;
  j = -1;
  tmp = prog->list;
  bunny_free(prog->colors);
  bunny_delete_ini(ini);
  if (tmp != NULL)
    {
      tmp = tmp->next;
      while (tmp != prog->list)
	{
	  tmp = tmp->next;
	  ++i;
	}
      while (++j < i)
	{
	  tmp = prog->list->next;
	  bunny_free(prog->list);
	  prog->list = tmp;
	}
    }
}
