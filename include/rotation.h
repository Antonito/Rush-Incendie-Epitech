/*
** rotation.h for gfx_incendie in /home/scutar_n/rendu/gfx_incendie/include
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Sun Dec  6 05:00:56 2015 nathan scutari
** Last update Sun Dec  6 19:01:29 2015 Antoine Baché
*/

#ifndef ROTATION_H_
# define ROTATION_H_
# define UNUSED __attribute__((unused))

# include <unistd.h>
# include <stdlib.h>
# include <lapin.h>

typedef struct		s_list
{
  unsigned int		palette;
  struct s_list		*next;
}			t_list;

typedef struct		s_prog
{
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
  int			rotation;
  int			*colors;
  t_list		*save;
  t_list		*list;
}			t_prog;

t_bunny_response	key(t_bunny_event_state, t_bunny_keysym key, void *);
t_bunny_response	mainloop(t_prog *);
int			syntax_check(const char *);
int			is_overflow(const char *, int);
long int       		my_getnbr(const char *);
void			draw_picture(t_bunny_pixelarray *, int *, t_list *);
int			get_colors(t_bunny_ini *, int, int *, char *);
void			reverse_list(t_list **);
int			set_ini(t_prog *, char *, int, t_bunny_ini *);
int			my_strlen(const char *);
int			malloc_list(t_list **, unsigned int, t_list **);
int			get_list(t_bunny_ini *, t_list **, const char *);
int			get_win_width(t_bunny_ini *, char *);
void			free_elems(t_prog *, t_bunny_ini *);
int			get_win_height(t_bunny_ini *, char *);
int			get_format(char *, char *);

#endif /* !ROTATION_H_ */
