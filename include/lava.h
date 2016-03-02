/*
** my_effect.h for gfx_incendie in /gfx_incendie/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Dec  5 07:42:52 2015 Antoine Baché
** Last update Sun Dec  6 10:40:54 2015 Antoine Baché
*/

#ifndef LAVA_H_
# define LAVA_H_
# define PALETTE_SIZE 256
# define WIN_X 1280
# define WIN_Y 1024
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
  unsigned int		palette[512];
  char			colors[WIN_X * (WIN_Y + 2)];
}			t_prog;

void			palette_generator(unsigned int *);
unsigned int		check_gradient(int);
void			display_lava(t_bunny_pixelarray *, char *,
				     unsigned int *);
int			pos_average(int, char *);
int			first_pos_average(int, char *);
int			last_pos_average(int, char *);
void			fx_calculator(char *);
t_bunny_response	key_lava(t_bunny_event_state, t_bunny_keysym, void *);
t_bunny_response	lavaloop(t_prog *);
void			random_lines(char *);

#endif /* !LAVA_H_ */
