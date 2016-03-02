/*
** plasma.h for gfx_incendie in /gfx_incendie/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Dec  5 08:30:58 2015 Antoine Baché
** Last update Sun Dec  6 10:31:54 2015 Antoine Baché
*/

#ifndef PLASMA_H_
# define PLASMA_H_
# define WIN_X 960
# define WIN_Y 640
# define PALETTE_SIZE 256
# define UNUSED __attribute__((unused))
# define ABS(x) ((x < 0) ? -x : x)

# include <lapin.h>
# include <math.h>

typedef struct		s_prog
{
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
  unsigned int		palette[PALETTE_SIZE];
  unsigned char		zoom;
  unsigned char		mod;
  short			*colors;
}			t_prog;

double			pos_calc(int, int, unsigned char);
unsigned int		check_gradient(int);
t_bunny_response	key(t_bunny_event_state, t_bunny_keysym, void *);
t_bunny_response	mainloop(t_prog *);
void			palette_generator(unsigned int *);
void			plasma_calculator(short *, unsigned char,
					  unsigned char);
void			display_plasma(t_bunny_pixelarray *, short *,
				       unsigned int *);

#endif /* !PLASMA_H_ */
