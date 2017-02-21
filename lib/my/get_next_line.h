/*
** get_next_line.h for get_next_line in /home/thibrex/Dropbox/delivery/CPE/CPE_2017_getnextline
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Jan  2 09:08:37 2017 Thibaut Cornolti
** Last update Tue Feb 14 00:16:38 2017 Thibaut Cornolti
*/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef READ_SIZE
# define READ_SIZE 256
#endif /* !READ_SIZE */

typedef struct	s_buffer
{
  int		fd;
  char		*buffer;
}		t_buffer;

char	*get_next_line(int);
void	fill_buffer(char **, const int);
int	fill_result(char **, char **);

#endif /* !GET_NEXT_LINE_H */
