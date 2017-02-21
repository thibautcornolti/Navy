/*
** navy.h for navy in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_navy
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Jan 30 09:51:51 2017 Thibaut Cornolti
** Last update Tue Feb  7 14:30:11 2017 Bastien
*/

#ifndef NAVY_H_
# define NAVY_h_

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "my.h"

# define GAME g_game

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef struct	s_player
{
  char		map[8][9];
  pid_t		pid;
  int		hit;
}		t_player;

struct		s_game
{
  t_player	me;
  t_player	enemy;
  char		receive_x;
  char		receive_y;
  char		receive_cs;
  char		receive_last;
  char		send_x;
  char		send_y;
  int		receive_nbr;
  long		wait;
}		g_game;

void		init_game();
void		print_maps();
void		parse_map(char *);
void		free_tab(char **);
void		start_server();
void		start_client();
int		check_map(char *);
void		free_tab(char **);
void	        receive_signal(int, siginfo_t *, void *);
void		send_signal(int, int);
void		check_win();
void		game_server();
void		game_client();
void		my_wait();
void		my_wait2();
void		print_result(int);
char		*format_it(char *);
int		my_encrypt(char, char);

#endif /* NAVY_H_ */
