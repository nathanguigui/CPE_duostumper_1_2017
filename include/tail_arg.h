/*
** EPITECH PROJECT, 2017
** tail
** File description:
** tail_arg.h
*/

#ifndef TAIL_ARG_
#define TAIL_ARG_

typedef struct tail_s {
	int size_type;
	int size_count;
	int verbose;
	char **files;
	char **errors;
	char *name;
	int error;
} tail_t;

#endif