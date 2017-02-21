/*
** send.c for navy in /home/rectoria/delivery/Projets/PSU_2016_navy
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Mon Jan 30 17:06:12 2017 Bastien
** Last update Wed Feb  8 15:09:08 2017 Thibaut Cornolti
*/

#include "navy.h"

int	fct_send(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    {
      if (str[i] == '0')
	kill(GAME.enemy.pid, SIGUSR1);
      else if (str[i] == '1')
	kill(GAME.enemy.pid, SIGUSR2);
      usleep(100);
    }
  return (0);
}

char	*fill_str(char *str)
{
  char	*new_str;
  int	i;
  int	j;

  i = -1;
  j = -1;
  if ((new_str = malloc(sizeof(char) * 5)) == NULL)
    return (NULL);
  while (++i < 4 - my_strlen(str))
    new_str[i] = '0';
  while (str[++j])
    new_str[i++] = str[j];
  new_str[i] = '\0';
  free(str);
  return (new_str);
}

char	*fill_strsum(char *str)
{
  char  *new_str;
  int   i;
  int   j;

  i = -1;
  j = -1;
  if ((new_str = malloc(sizeof(char) * 9)) == NULL)
    return (NULL);
  while (++i < 8 - my_strlen(str))
    new_str[i] = '0';
  while (str[++j])
    new_str[i++] = str[j];
  new_str[i] = '\0';
  free(str);
  return (new_str);
}

void	send_signal(int x, int y)
{
  char	*charx;
  char	*chary;
  char	*checksum;
  char	*tmp;

  GAME.send_x = x;
  GAME.send_y = y;
  usleep(100);
  tmp = my_int_to_str(x, NULL);
  charx = fill_str(convert_base(tmp, "0123456789", "01"));
  free(tmp);
  tmp = my_int_to_str(y, NULL);
  chary = fill_str(convert_base(tmp, "0123456789", "01"));
  free(tmp);
  tmp = my_int_to_str(my_encrypt(x, y), NULL);
  checksum = fill_strsum(convert_base(tmp, "0123456789", "01"));
  free(tmp);
  while (fct_send(my_strmcat(my_strmcat(charx, chary),
			    checksum)) == -1);
  my_wait2();
}
