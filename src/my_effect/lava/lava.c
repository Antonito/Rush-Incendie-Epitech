/*
** main.c for gfx_incendie in /gfx_incendie/src/my_effect
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Dec  5 07:46:21 2015 Antoine Baché
** Last update Sun Dec  6 10:40:22 2015 Antoine Baché
*/

#include "lava.h"

t_bunny_response	key_lava(t_bunny_event_state state,
			    t_bunny_keysym key,
			    UNUSED void *p)
{
  if (key == BKS_ESCAPE && state == GO_DOWN)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	lavaloop(t_prog *prog)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 0;
  random_lines(prog->colors);
  fx_calculator(prog->colors);
  display_lava(prog->pix, prog->colors, prog->palette);
  bunny_blit(&(prog->win->buffer), &(prog->pix->clipable), &pos);
  bunny_display(prog->win);
  return (GO_ON);
}

int		lava()
{
  t_prog	*prog;

  if ((prog = bunny_malloc(sizeof(t_prog))) == NULL)
    return (-1);
  palette_generator(prog->palette);
  srand(time(NULL));
  prog->win = bunny_start(WIN_X, WIN_Y, 0, "Lava");
  prog->pix = bunny_new_pixelarray(WIN_X, WIN_Y + 2);
  bunny_set_loop_main_function((t_bunny_loop)lavaloop);
  bunny_set_key_response(key_lava);
  bunny_loop(prog->win, 60, prog);
  bunny_stop(prog->win);
  bunny_delete_clipable(&prog->pix->clipable);
  bunny_free(prog);
  return (0);
}
