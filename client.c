/*
** client.c for navy in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_navy
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Jan 30 15:27:58 2017 Thibaut Cornolti
** Last update Wed Feb  1 17:45:01 2017 Thibaut Cornolti
*/

#include <signal.h>
#include "navy.h"

void	start_client()
{
  send_signal(9, 9);
  my_putstr("my_pid: ");
  my_put_nbr(GAME.me.pid);
  my_putstr("\nsuccessfully connected\n\n");
  print_maps();
  game_client();
  check_win();
}
