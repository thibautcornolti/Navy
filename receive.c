/*
** receive.c for navy in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_navy
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Jan 30 15:19:50 2017 Thibaut Cornolti
** Last update Sun Feb  5 22:06:58 2017 Thibaut Cornolti
*/

#include <signal.h>
#include <time.h>
#include "navy.h"

int		receive_checksum()
{
  if (GAME.receive_cs == my_encrypt(GAME.receive_x, GAME.receive_y))
    return (1);
  return (0);
}

static void	make_signal(int r)
{
  if (GAME.receive_nbr < 4)
    {
      if (GAME.receive_nbr == 0)
	GAME.receive_x = r;
      else
	GAME.receive_x = (GAME.receive_x << 1) | r;
    }
  else if (GAME.receive_nbr < 8)
    {
      if (GAME.receive_nbr == 4)
	GAME.receive_y = r;
      else
	GAME.receive_y = (GAME.receive_y << 1) | r;
    }
  else
    {
      if (GAME.receive_nbr == 8)
	GAME.receive_cs = r;
      else
	GAME.receive_cs = (GAME.receive_cs << 1) | r;
    }
}

void		receive_signal(int sig, siginfo_t *siginfo,
			       void *context)
{
  int		r;

  (void) context;
  if (GAME.enemy.pid == 0)
    GAME.enemy.pid = siginfo->si_pid;
  else if (GAME.enemy.pid != siginfo->si_pid)
    return ;
  GAME.wait = 0;
  GAME.receive_last = (r = (sig == SIGUSR1) ? 0 : 1);
  make_signal(r);
  GAME.receive_nbr += 1;
  if (GAME.receive_nbr == 16 && receive_checksum() == 0)
    {
      usleep(5000);
      GAME.receive_nbr = 0;
      kill(GAME.enemy.pid, SIGUSR2);
    }
  else if (GAME.receive_nbr == 16)
    {
      usleep(5000);
      kill(GAME.enemy.pid, SIGUSR1);
    }
  if (GAME.receive_nbr > 16)
    GAME.receive_nbr = 0;
}
