/*
** my_getnbr.c for gfx_incendie in /gfx_incendie/src/rotation
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Sun Dec  6 07:57:29 2015 nathan scutari
** Last update Sun Dec  6 11:29:58 2015 Antoine Baché
*/

#include "rotation.h"

int	is_overflow(const char *tab, int length)
{
  int	i;
  char	max_int[] = "4294967295";

  i = 0;
  if (length > 10)
    return (1);
  if (length < 10)
    return (0);
  while (tab[i] != 0)
    {
      if (tab[i] > max_int[i])
	return (1);
      i++;
    }
  return (0);
}

int	syntax_check(const char *str)
{
  int	i;

  i = -1;
  while (str[++i] != 0)
    if (str[i] < '0' || str[i] > '9')
      return (1);
  return (0);
}

long int       	my_getnbr(const char *str)
{
  int		i;
  int		dec;
  unsigned int	nbr;

  i = my_strlen(str);
  if (syntax_check(str))
    return (-1);
  if (is_overflow(str, i))
    return (-1);
  dec = 1;
  nbr = 0;
  while (--i >= 0)
    {
      nbr += (str[i] - 48) * dec;
      dec *= 10;
    }
  return (nbr);
}
