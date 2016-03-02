/*
** music_settings.c for gfx_incendie in /gfx_incendie/src/fire
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Sun Dec  6 03:55:34 2015 nathan scutari
** Last update Sun Dec  6 05:41:41 2015 Antoine Baché
*/

#include "fire.h"

int	load_music(t_bunny_music * music)
{
  bunny_sound_loop(music, 1);
  bunny_sound_volume(music, 20);
  bunny_sound_play(music);
  return (0);
}
