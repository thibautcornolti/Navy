/*
** win_cond.c for navy in /home/rectoria/delivery/Projets/PSU_2016_navy
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Tue Jan 31 11:48:18 2017 Bastien
** Last update Sun Feb  5 22:14:34 2017 Thibaut Cornolti
*/

#include "navy.h"

void	check_win()
{
  print_maps();
  if (GAME.me.hit >= 14)
    my_putstr("\nEnemy won\n");
  else if (GAME.enemy.hit >= 14)
    my_putstr("\nI won\n");
}
