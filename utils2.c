/*
** utils2.c for navy in /home/rectoria/delivery/Projets/PSU_2016_navy
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Thu Feb  2 16:14:21 2017 Bastien
** Last update Tue Feb 14 00:17:46 2017 Thibaut Cornolti
*/

#include "navy.h"

void	my_wait2()
{
  int	i;

  i = -1;
  while (++i < 100000 && GAME.receive_nbr < 1)
    usleep(10);
  GAME.receive_nbr = 0;
  if (i >= 1000 || GAME.receive_last == 1)
    send_signal(GAME.send_x, GAME.send_y);
}

void	my_wait()
{
  GAME.receive_nbr = 0;
  GAME.wait = 0;
  GAME.receive_x = 0;
  GAME.receive_y = 0;
  while (GAME.receive_nbr < 16)
    {
      if (GAME.receive_nbr > 0 && GAME.wait > 10000)
	{
	  GAME.receive_nbr = 0;
	  GAME.receive_x = 0;
	  GAME.receive_y = 0;
	  GAME.wait = 0;
	  kill(GAME.enemy.pid, SIGUSR2);
	}
      usleep(10);
      GAME.wait += 1;
    }
  GAME.receive_nbr = 0;
}

int	my_encrypt(char c, char v)
{
  return (c * 10 + v);
}
