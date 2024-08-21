/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:19:46 by selango           #+#    #+#             */
/*   Updated: 2024/07/02 19:02:42 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <limits.h>
#include <unistd.h>
#include<stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#ifndef OPEN_MAX
#define OPEN_MAX 1024
#endif

size_t ft_strlen(const char *str);
char *ft_strdup(const char *src);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strchr(const char *s, int c);
char *ft_substr(const char *s, unsigned int start, size_t len);
char *get_next_line(int fd);

#endif
