/*
** fct_free.c for navy in /home/rectoria/delivery/Projets/PSU_2016_navy
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Mon Jan 30 13:53:24 2017 Bastien
** Last update Mon Jan 30 14:00:35 2017 Bastien
*/

#include <stdlib.h>

void	free_tab(char **tab)
{
  int	i;

  i = -1;
  if (tab == NULL)
    return ;
  while (tab[++i])
    free(tab[i]);
  free(tab);
}
