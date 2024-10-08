/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:19:43 by selango           #+#    #+#             */
/*   Updated: 2024/07/02 20:29:41 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char* read_lines(int fd,char *buff,char *store)
{
    int bytes;
    char *temp;
    int iteration_count = 0;

    bytes = 1;
    while(bytes && iteration_count < 10000)
    {
        bytes = read(fd,buff,BUFFER_SIZE);
        if(bytes == -1)
            return(0);
        else if (bytes == 0)
            break;
        buff[bytes] = '\0';
        if(!store)
            store = ft_strdup("");
        temp = store;
        store = ft_strjoin(temp,buff);
        if(!store)
            return(NULL);
        free(temp);
        temp = NULL;
        if(ft_strchr(buff,'\n'))
            break;
    }
    return(store);
}

static char* update(char *lines)
{
    int i;
    char *temp;

    i = 0;
    while(lines[i] != '\0' && lines[i] != '\n')
        i++;
    if(lines[i] == '\0')
        return(NULL);
    temp = ft_substr(lines, i + 1,ft_strlen(lines) - i);
    if(!temp)
        return(NULL);
    if(temp[0] == '\0')
    {
        free(temp);
        temp = NULL;
        return(NULL);
    }
    lines[i + 1] = '\0';
    return(temp);
} 

char *get_next_line(int fd)
{
    char        *buff;
    char        *lines;
    static char *store[OPEN_MAX];
    

    if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
        return(NULL);
    buff = malloc(sizeof(char) *(BUFFER_SIZE + 1));
    if(!buff)
        return(NULL);
    lines = read_lines(fd,buff,store[fd]);
    free(buff);
    if(!lines)
        return(NULL);
    store[fd] = update(lines);
    return(lines);
}


// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     int fd;
//     char *line;
//     const char *filename = "file.txt"; // Change this to your desired filename

//     fd = open(filename, O_RDONLY);
//     if (fd < 0)
//     {
//         perror("Error opening file");
//         return (1);
//     }

//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }

//     close(fd);
//     return (0);
// }

