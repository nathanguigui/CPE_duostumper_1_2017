/*
** EPITECH PROJECT, 2018
** tail
** File description:
** tail.h
*/

#ifndef TAIL_H_
#define TAIL_H_

#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>

#include "my.h"
#include "tail_arg.h"
#include "get_next_line.h"

char **get_file(tail_t *tail, int fd, int i, char **file2);
tail_t *get_struct(int ac, char **av);
void yolo(char **line, char **file2);
int get_ac(char **argv);
void tail_view(char **file, char *str_file, tail_t *tail_ag);
int *get_fds(tail_t *tail);
void tail_verb(tail_t *tail_ag, int i, int fd);
void free_struct(tail_t *tail);

#endif
