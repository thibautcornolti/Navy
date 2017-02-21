/*
** shower.c for navy in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_navy
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Jan 30 15:06:01 2017 Thibaut Cornolti
** Last update Sun Feb  5 22:07:28 2017 Thibaut Cornolti
*/

#include "navy.h"

void		print_result(int hit)
{
  my_putchar(GAME.receive_x + 'A');
  my_putchar(GAME.receive_y + '1');
  if (hit)
    my_putstr(": hit\n\n");
  else
    my_putstr(": missed\n\n");
}

static void	print_tab(char t[8][9])
{
  int		i;
  int		j;

  i = -1;
  my_putstr(" |A B C D E F G H\n");
  my_putstr("-+---------------\n");
  while (++i <= 7)
    {
      my_put_nbr(i + 1);
      my_putstr("|");
      j = -1;
      while (++j <= 6)
	{
	  my_putchar(t[i][j]);
	  my_putchar(' ');
	}
      my_putchar(t[i][j]);
      my_putchar('\n');
    }
}

void		print_maps()
{
  my_putstr("my positions:\n");
  print_tab(GAME.me.map);
  my_putstr("\nenemy's positions:\n");
  print_tab(GAME.enemy.map);
}
