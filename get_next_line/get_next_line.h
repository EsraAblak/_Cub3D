/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:00:45 by eablak            #+#    #+#             */
/*   Updated: 2023/05/15 13:50:56 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h> 
# include <errno.h> 

size_t	ft_g_strlen(char *s);
char	*ft_g_strchr(char *s, int c);
char	*ft_g_strjoin(char *s1, char *s2);
char	*ft_bring(char *all_line);
char	*ft_take_rest(char *all_line);
char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
#endif
