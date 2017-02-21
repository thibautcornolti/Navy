/*
** utils.c for navy in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_navy
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Jan 30 10:18:04 2017 Thibaut Cornolti
** Last update Sun Feb  5 22:07:47 2017 Thibaut Cornolti
*/

#include <signal.h>
#include "navy.h"

char	*format_it(char *str)
{
  int	i;
  char	c;

  i = -1;
  if (str == NULL)
    return (str);
  while (str[++i])
    if (str[i] >= 'a' && str[i] <= 'z')
      str[i] -= 32;
  if (str[0] >= '0' && str[0] <= '9')
    {
      c = str[0];
      str[0] = str[1];
      str[1] = c;
    }
  return (str);
}

static void		my_memclean(void *v, int n)
{
  int			i;
  unsigned char		*ptr;

  ptr = v;
  i = -1;
  while (++i < n)
    {
      *ptr = 0;
      ptr += 1;
    }
}

void			init_sig()
{
  struct sigaction	act;

  my_memclean(&act, sizeof(act));
  act.sa_sigaction = &receive_signal;
  act.sa_flags = SA_SIGINFO;
  sigaction(SIGUSR1, &act, NULL);
  sigaction(SIGUSR2, &act, NULL);
}

static void		init_var()
{
  GAME.me.pid = getpid();
  GAME.enemy.pid = 0;
  GAME.receive_x = 0;
  GAME.receive_y = 0;
  GAME.receive_nbr = 0;
  GAME.send_x = 100;
  GAME.send_y = 100;
  GAME.me.hit = 0;
  GAME.enemy.hit = 0;
}

void			init_game()
{
  int			i;
  int			j;

  init_sig();
  init_var();
  i = 0;
  while (i <= 7)
    {
      j = 0;
      while (j <= 7)
	{
	  GAME.me.map[i][j] = '.';
	  GAME.enemy.map[i][j] = '.';
	  j += 1;
	}
      GAME.me.map[i][j] = 0;
      GAME.enemy.map[i][j] = 0;
      i += 1;
    }
}
