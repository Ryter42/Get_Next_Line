/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:10:15 by emoreau           #+#    #+#             */
/*   Updated: 2023/02/14 05:17:49 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*nextline(int fd);
char	*inistash(char *stash);
int		backslash(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strlen_gnl(const char *str);
int		sizeline(char *str);
void	*ft_calloc_gnl(size_t nmemb, size_t size);
char	*freestash(char *stash);

#endif