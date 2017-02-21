/*
** check_map.c for navy in /home/rectoria/delivery/Projets/PSU_2016_navy
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Mon Jan 30 13:32:09 2017 Bastien
** Last update Fri Feb  3 16:57:27 2017 Thibaut Cornolti
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "navy.h"
#include "my.h"

int	len_tab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i]);
  return (i);
}

int	len(char *str)
{
  int	i;

  i = -1;
  if (str == NULL)
    return (0);
  while (str[++i]);
  return (i);
}

int	check_valid(char **tab)
{
  int	i;

  i = 0;
  if (len(tab[0]) != 1 || (tab[0][0] < '2' || tab[0][0] > '5'))
    return (-1);
  while (tab[++i])
    {
      if (len(tab[i]) != 2)
	return (-1);
      if (tab[i][0] < 'A' || tab[i][0] > 'H' ||
	  tab[i][1] < '1' || tab[i][1] > '8')
	return (-1);
    }
  if (tab[1][0] == tab[2][0] || tab[1][1] == tab[2][1])
    {
      if (tab[1][0] - tab[2][0] == tab[0][0] - '1' ||
	  tab[2][0] - tab[1][0] == tab[0][0] - '1')
	return (0);
      if (tab[1][1] - tab[2][1] == tab[0][0] - '1' ||
	  tab[2][1] - tab[1][1] == tab[0][0] - '1')
	return (0);
    }
  return (-1);
}

int	error_map(int fd, char **tab)
{
  close(fd);
  if (tab != NULL)
    free_tab(tab);
  return (-1);
}

int	check_map(char *pathname)
{
  int	fd;
  char	boat_size;
  char	*s;
  char	**tab;

  boat_size = '2';
  if ((fd = open(pathname, O_RDONLY)) < 0)
    return (-1);
  while ((s = get_next_line(fd)) != NULL)
    {
      if ((tab = my_strsplit(s, ':')) == NULL)
	return (error_map(fd, tab));
      if (len_tab(tab) != 3 || check_valid(tab) == -1)
	return (error_map(fd, tab));
      if (boat_size != tab[0][0])
	return (error_map(fd, tab));
      free_tab(tab);
      boat_size += 1;
    }
  if (boat_size != '6')
    return (error_map(fd, NULL));
  close(fd);
  return (0);
}
