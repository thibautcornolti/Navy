/*
** my_strdup.c for my_strdup in /home/thibrex/delivery/CPool_Day08/task01
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu@epitech.net>
** 
** Started on  Wed Oct 12 09:39:31 2016 Thibaut Cornolti
** Last update Mon Jan 30 10:15:33 2017 Thibaut Cornolti
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  char	*dup;
  int	i;

  if ((dup = malloc(sizeof(char) * my_strlen(src) + 1)) == NULL)
    return ((char *) (long) my_puterror("error"));
  i = 0;
  while (src[i] != 0)
    {
      dup[i] = src[i];
      i += 1;
    }
  dup[i] = 0;
  return (dup);
}
