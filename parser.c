/*
** parser.c for navy in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_navy
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Jan 30 10:09:09 2017 Thibaut Cornolti
** Last update Mon Jan 30 15:59:18 2017 Thibaut Cornolti
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "navy.h"

static void	trace_pos(t_pos from, t_pos to, int ship)
{
  if (from.x == to.x)
    {
      if (from.y < to.y)
        while (from.y <= to.y)
	  GAME.me.map[from.y++][from.x] = ship + '0';
      else
        while (from.y >= to.y)
	  GAME.me.map[from.y--][from.x] = ship + '0';
    }
  else
    {
      if (from.x < to.x)
        while (from.x <= to.x)
	  GAME.me.map[from.y][from.x++] = ship + '0';
      else
        while (from.x >= to.x)
	  GAME.me.map[from.y][from.x--] = ship + '0';
    }
}

void		parse_map(char *filepath)
{
  int		fd;
  char		*line;
  char		**split;
  int		ship;
  t_pos		from;
  t_pos		to;

  fd = open(filepath, O_RDONLY);
  if (fd == -1)
    return ;
  ship = 2;
  while ((line = get_next_line(fd)))
    {
      split = my_strsplit(line, ':');
      from.x = split[1][0] - 'A';
      from.y = split[1][1] - '1';
      to.x = split[2][0] - 'A';
      to.y = split[2][1] - '1';
      trace_pos(from, to, ship);
      free_tab(split);
      ship += 1;
    }
  close(fd);
}
