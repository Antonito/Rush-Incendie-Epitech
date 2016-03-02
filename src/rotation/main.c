/*
** main.c for gfx_incendie in /home/scutar_n/rendu/gfx_incendie/src/rotation
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Sun Dec  6 04:57:30 2015 nathan scutari
** Last update Sun Dec  6 19:09:10 2015 Antoine Baché
*/

#include "rotation.h"

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym key,
			    void *p)
{
  if (key == BKS_R && state == GO_DOWN)
    ((t_prog *)p)->list = ((t_prog *)p)->save;
  if (key == BKS_SPACE && state == GO_DOWN)
    ((t_prog *)p)->rotation = 1;
  if (key == BKS_SPACE && state == GO_UP)
    ((t_prog *)p)->rotation = 0;
  if (key == BKS_ESCAPE && state == GO_DOWN)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	mainloop(t_prog *prog)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 0;
  if (prog->rotation)
    prog->list = prog->list->next;
  draw_picture(prog->pix, prog->colors, prog->list);
  bunny_blit(&(prog->win->buffer), &(prog->pix->clipable), &pos);
  bunny_display(prog->win);
  return (GO_ON);
}

int	set_ini(t_prog *prog, char *file_format, int size,
		t_bunny_ini *ini)
{
  prog->list = NULL;
  if (get_list(ini, &prog->list, file_format) == -1)
    return (-1);
  if (get_colors(ini, size, prog->colors, file_format) == -1)
    return (-1);
  prog->rotation = 0;
  prog->save = prog->list;
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_set_key_response(key);
  return (0);
}

int		rotation(int ac, char **av)
{
  int		win_x;
  int		win_y;
  t_prog	prog;
  t_bunny_ini	*ini;
  char		*file_format;

  if ((ac < 2 || (ini = bunny_load_ini(av[1])) == NULL))
    return (-1);
  if ((file_format = bunny_malloc(my_strlen(av[1]))) == NULL)
    return (-1);
  if (get_format(av[1], file_format) == -1)
    return (-1);
  win_x = get_win_width(ini, file_format);
  win_y = get_win_height(ini, file_format);
  prog.win = bunny_start(win_x, win_y, 0, "Picture");
  prog.pix = bunny_new_pixelarray(win_x, win_y);
  if ((prog.colors = bunny_malloc(sizeof(int) * win_x * win_y)) == NULL)
    return (-1);
  if ((set_ini(&prog, file_format, win_x * win_y, ini)) == -1)
    return (-1);
  bunny_loop(prog.win, 10, &prog);
  free_elems(&prog, ini);
  bunny_delete_clipable(&prog.pix->clipable);
  bunny_stop(prog.win);
  return (0);
}

int	main(int ac, char **av, char **env)
{
  if (*env == NULL)
    return (1);
  else if (ac != 2)
    {
      write(2, "Usage: ./rotation ini_file\n", 27);
      return (1);
    }
  else if (rotation(ac, av) == -1)
    return (1);
  return (0);
}
