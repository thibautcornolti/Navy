/*
** game.c for navy in /home/rectoria/delivery/Projets/PSU_2016_navy
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Tue Jan 31 13:21:48 2017 Bastien
** Last update Fri Feb 17 11:19:58 2017 Thibaut Cornolti
*/

#include "navy.h"

int	apply_map_hit(int i, char *s)
{
  if (i == 1)
    {
      if (GAME.enemy.map[(int) s[1] - '1'][(int) s[0] - 'A'] != 'x')
	{
	  GAME.enemy.map[(int) s[1] - '1'][(int) s[0] - 'A'] = 'x';
	  GAME.enemy.hit += 1;
	  return (1);
	}
    }
  else
    GAME.enemy.map[(int) s[1] - '1'][(int) s[0] - 'A']= 'o';
  return (0);
}

int	check_hit(int i, char *s)
{
  if (i == 1 && GAME.receive_x == 9 && GAME.receive_y == 9)
    return (apply_map_hit(1, s));
  else if (i == 1)
    return (apply_map_hit(0, s));
  else if (i == 0 && (GAME.me.map[(int) GAME.receive_y]
		      [(int) GAME.receive_x] != '.'))
    {
      if (GAME.me.map[(int) GAME.receive_y]
	  [(int) GAME.receive_x] != 'x')
	print_result(1 + 0 * (GAME.me.hit += 1));
      else
	print_result(0);
      GAME.me.map[(int) GAME.receive_y][(int) GAME.receive_x] = 'x';
      return (1);
    }
  else if (i == 0)
    {
      print_result(0);
      GAME.me.map[(int) GAME.receive_y][(int) GAME.receive_x] = 'o';
      return (0);
    }
  return (0);
}

int	check_entry(char *s)
{
  if (s == NULL)
    return (0);
  if (my_strlen(s) != 2)
    return (0 + my_putstr("wrong position\nattack: "));
  if (s[0] >= 'A' && s[0] <= 'H' && s[1] > '0' && s[1] <= '8')
    return (1);
  return (0 + my_putstr("wrong position\nattack: "));
}

void	game_client()
{
  char *s;

  while (GAME.me.hit < 14 && GAME.enemy.hit < 14)
    {
      my_putstr("\nwaiting for enemy's attack...\n");
      my_wait();
      if (check_hit(0, s))
	send_signal(9, 9);
      else
	send_signal(8, 8);
      if (GAME.me.hit < 14 && GAME.enemy.hit < 14)
	{
	  my_putstr("attack: ");
	  while (check_entry(format_it(s = get_next_line(0))) != 1);
	  send_signal(s[0] - 'A', s[1] - '1');
	  my_wait();
	  if (check_hit(1, s))
	    my_putstr(my_putstr(s) + ": hit\n\n");
	  else
	    my_putstr(my_putstr(s) + ": missed\n\n");
	  print_maps();
	}
    }
}

void	game_server()
{
  char	*s;

  while (GAME.me.hit < 14 && GAME.enemy.hit < 14)
    {
      my_putstr("\nattack: ");
      while (check_entry(format_it(s = get_next_line(0))) != 1);
      send_signal(s[0] - 'A', s[1] - '1');
      my_wait();
      if (check_hit(1, s))
	my_putstr(my_putstr(s) + ": hit\n\n");
      else
	my_putstr(my_putstr(s) + ": missed\n\n");
      if (GAME.me.hit < 14 && GAME.enemy.hit < 14)
	{
	  my_putstr("waiting for enemy's attack...\n");
	  my_wait();
	  if (check_hit(0, s))
	    send_signal(9, 9);
	  else
	    send_signal(8, 8);
	  print_maps();
	}
    }
}
