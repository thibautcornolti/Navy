/*
** main.c for navy in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_navy
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Jan 30 09:23:57 2017 Thibaut Cornolti
** Last update Sun Feb  5 22:06:44 2017 Thibaut Cornolti
*/

#include "navy.h"

int	main(int ac, char **av)
{
  init_game();
  if (ac == 2)
    {
      if (check_map(av[1]) == -1)
	return (84 + my_puterror("Wrong map format.\n"));
      parse_map(av[1]);
      start_server();
    }
  else if (ac == 3)
    {
      if (check_map(av[2]) == -1)
	return (84 + my_puterror("Wrong map format.\n"));
      GAME.enemy.pid = my_getnbr(av[1]);
      parse_map(av[2]);
      start_client();
    }
  else
    return (0);
  return (0);
}
