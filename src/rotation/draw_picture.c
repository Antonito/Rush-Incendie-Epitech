/*
** draw_picture.c for gfx_incendie in /gfx_incendie/src/rotation
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Sun Dec  6 06:56:11 2015 nathan scutari
** Last update Sun Dec  6 11:38:01 2015 Antoine Baché
*/

#include "rotation.h"

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str != NULL)
    i++;
  return (i);

}

void		reverse_list(t_list **list)
{
  t_list	*tmp;
  t_list	*previous;
  t_list	*save;
  t_list	*list_b;

  tmp = *list;
  previous = NULL;
  while (tmp != NULL)
    {
      save = tmp->next;
      tmp->next = previous;
      previous = tmp;
      list_b = tmp;
      tmp = save;
    }
  *list = list_b;
}

void		draw_picture(t_bunny_pixelarray *pix, int *colors,
		     t_list *list)
{
  int		i;
  int		j;
  int		win_x;
  int		win_y;
  t_color	*color;
  t_list	*tmp;

  i = -1;
  win_x = pix->clipable.clip_width;
  win_y = pix->clipable.clip_height;
  color = pix->pixels;
  while (++i < win_x * win_y)
    {
      j = -1;
      tmp = list;
      while (++j < colors[i])
	tmp = tmp->next;
      color[i].full = tmp->palette;
    }
}
