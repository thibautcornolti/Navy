/*
** my_strmcat.c for my_strmcat in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_navy/lib/my
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Wed Feb  8 15:09:40 2017 Thibaut Cornolti
** Last update Wed Feb  8 15:13:24 2017 Thibaut Cornolti
*/

#include <stdlib.h>

char	*my_strmcat(char *str1, char *str2)
{
  char	*result;
  int	len1;
  int	len2;
  int	i;
  int	j;

  if (str2 == NULL)
    return (str1);
  if (str1 == NULL)
    return (str2);
  len1 = -1;
  while (str1[++len1]);
  len2 = -1;
  while (str2[++len2]);
  if ((result = malloc(sizeof(char) * (len1 + len2 + 1))) == NULL)
    return (NULL);
  i = -1;
  j = -1;
  while (str1[++i])
    result[++j] = str1[i];
  i = -1;
  while (str2[++i])
    result[++j] = str2[i];
  result[++j] = 0;
  return (result);
}
