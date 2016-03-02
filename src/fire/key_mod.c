/*
** key_mod.c for gfx_incendie in /home/scutar_n/rendu/gfx_incendie/src/fire
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Sat Dec  5 20:27:52 2015 nathan scutari
** Last update Sat Dec  5 20:31:18 2015 nathan scutari
*/

#include "fire.h"

void	go_up_key(t_bunny_keysym key, void *prog)
{
  if (key == BKS_UP)
      ((t_prog *)prog)->mod[0] = 0;
  else if (key == BKS_DOWN)
    ((t_prog *)prog)->mod[1] = 0;
}

void	go_down_key(t_bunny_keysym key, void *prog)
{
  if (key == BKS_UP)
    ((t_prog *)prog)->mod[0] = 1;
  else if (key == BKS_DOWN)
    ((t_prog *)prog)->mod[1] = 1;
}
