/*
** server.c for navy in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_navy
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Jan 30 15:20:42 2017 Thibaut Cornolti
** Last update Thu Feb 16 17:09:42 2017 Thibaut Cornolti
*/

#include "navy.h"

void		start_server()
{
  my_putstr("my_pid: ");
  my_put_nbr(GAME.me.pid);
  my_putstr("\nwaiting for enemy connexion...\n");
  my_wait();
  my_putstr("enemy connected\n\n");
  print_maps();
  game_server();
  check_win();
}
