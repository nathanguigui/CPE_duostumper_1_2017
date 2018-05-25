/*
** EPITECH PROJECT, 2017
** tail
** File description:
** tail_arg.c
*/

#include "tail.h"

void error_manage(tail_t *result, char **av, int *curr, int stat)
{
	char *debug;

	if (stat == 1) {
		result->size_type = 1;
		debug = ": invalid number of bytes: ‘";
	} else {
		result->size_type = 2;
		debug = ": invalid number of lines: ‘";
	}
	if (!is_number(av[*curr + 1])) {
		infin_puterr(4, result->name, debug, av[*curr + 1], "’\n");
		result->error = 1;
		return;
	} else
		result->size_count = my_getnbr(av[*curr + 1]);
}

void detect_param(tail_t *result, char **av, int *curr)
{
	int x = 0;

	if (my_strcmp("-c", av[*curr]) || my_strcmp("--bytes", av[*curr])) {
		error_manage(result, av, curr, 1);
		*curr = *curr + 1;
	}
	if (my_strcmp("-n", av[*curr]) || my_strcmp("--lines", av[*curr])) {
		error_manage(result, av, curr, 2);
		*curr = *curr + 1;
	}
	(my_strcmp("-q", av[*curr])) ? result->verbose = 0 : x = -1;
	(my_strcmp("--quiet", av[*curr])) ? result->verbose = 0 : x = -1;
	(my_strcmp("--silent", av[*curr])) ? result->verbose = 0 : x = -1;
	(my_strcmp("-v", av[*curr])) (file[lines - i] ? 1 : 0)? result->verbose = 1 : x = -1;
	(my_strcmp("--verbose", av[*curr])) ? result->verbose = 1 : x = -1;

	if (x == -1)
		tail_erro(result, av[*curr]);
	
}

void free_struct(tail_t *tail)
{
	free_array((void **)tail->files);
	free_array((void **)tail->errors);
	free(tail);
}

tail_t *init_strcut(void)
{
	tail_t *result = malloc(sizeof(tail_t));

	result->size_type = 2;
	result->size_count = 10;
	result->verbose = 2;
	result->files = NULL;
	result->errors = NULL;
	result->error = 0;
	return (result);
}

tail_t *get_struct(UNUSED int ac, char **av)
{
	tail_t *result = init_strcut();
	int current = 1;

	result->name = av[0];
	while (av[current]) {
		if  (av[current][0] == '-')
			detect_param(result, av, &current);
		else
			realloc_tab((void ***)&result->files,
			my_strcat(av[current], ""));
		current = current + 1;
	}
	return (result);
}
