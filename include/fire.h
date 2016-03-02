/*
** fire.h for gfx_incendie in /gfx_incendie/include
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Fri Dec  4 21:16:45 2015 nathan scutari
** Last update Sun Dec  6 19:03:36 2015 Antoine Baché
*/

#ifndef FIRE_H_
# define FIRE_H_
# define PALETTE_SIZE 256
# define WIN_X 1280
# define WIN_Y 512
# define WHITE_COLOR 0xFFFFFF
# define BLACK_COLOR 0x000000
# define UNUSED __attribute__((unused))

# include <stdlib.h>
# include <lapin.h>
# include <time.h>

typedef struct		s_prog
{
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
  t_bunny_music		*music;
  short			colors[WIN_X * (WIN_Y + 2)];
  int			mod[3];
  unsigned int		palette[PALETTE_SIZE];
}			t_prog;

void			palette_generator(unsigned int *);
unsigned int		check_gradient(int);
void			display_fire(t_bunny_pixelarray *, short *,
				     unsigned int *);
int			pos_average(int, short *, int);
int			first_pos_average(int, short *);
int			last_pos_average(int, short *);
void			fire_calculator(short *, int);
t_bunny_response	key(t_bunny_event_state, t_bunny_keysym, void *);
t_bunny_response	key(t_bunny_event_state, t_bunny_keysym, void *);
t_bunny_response	mainloop(t_prog *);
void			random_lines(short *);
int			flame();
int			intensity_mod(int, int);
int			load_music(t_bunny_music *);
void			go_up_key(t_bunny_keysym, void *);
void			set_to_black(short *);
void			go_down_key(t_bunny_keysym, void *);

#endif /* !FIRE_H_ */
