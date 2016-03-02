/*
** main.c for gfx_incendie in /gfx_incendie/src/plasma
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Dec  5 08:37:58 2015 Antoine Baché
** Last update Sun Dec  6 10:31:21 2015 Antoine Baché
*/

#include "plasma.h"

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym key,
			    void *p)
{
  if (key == BKS_ESCAPE && state == GO_DOWN)
    return (EXIT_ON_SUCCESS);
  if (key == BKS_UP && state == GO_DOWN && ((t_prog *)p)->zoom < 255)
    ((t_prog *)p)->zoom++;
  if (key == BKS_DOWN && state == GO_DOWN && ((t_prog *)p)->zoom > 1)
    ((t_prog *)p)->zoom--;
  return (GO_ON);
}

t_bunny_response	mainloop(t_prog *prog)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 0;
  if (prog->mod == 255)
    prog->mod = 0;
  else
    prog->mod++;
  plasma_calculator(prog->colors, prog->zoom, prog->mod);
  display_plasma(prog->pix, prog->colors, prog->palette);
  bunny_blit(&(prog->win->buffer),
	     &(prog->pix->clipable), &pos);
  bunny_display(prog->win);
  return (GO_ON);
}

int		plasma()
{
  t_prog	*prog;

  if ((prog = bunny_malloc(sizeof(t_prog))) == NULL)
    return (-1);
  else if ((prog->colors = bunny_malloc(sizeof(short) *
					WIN_X * WIN_Y)) == NULL)
    return (-1);
  palette_generator(prog->palette);
  prog->zoom = 1;
  prog->mod = 0;
  prog->win = bunny_start(WIN_X, WIN_Y, 0, "Plasma");
  prog->pix = bunny_new_pixelarray(WIN_X, WIN_Y);
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_set_key_response(key);
  bunny_loop(prog->win, 60, prog);
  bunny_stop(prog->win);
  bunny_delete_clipable(&prog->pix->clipable);
  bunny_free(prog->colors);
  bunny_free(prog);
  return (0);
}

int		main(UNUSED int ac, UNUSED char **av, char **env)
{
  if (*env == NULL || plasma() == -1)
    return (-1);
  return (0);
}
