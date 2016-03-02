/*
** main.c for gfx_incendie in /gfx_incendie/src/my_effect
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Dec  5 07:46:21 2015 Antoine Baché
** Last update Sun Dec  6 19:09:35 2015 Antoine Baché
*/

#include "my_effect.h"

int	main(UNUSED int ac, UNUSED char **av, char **env)
{
  if (*env == NULL || lava() == -1)
    return (-1);
  return (0);
}
