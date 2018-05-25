/*
** EPITECH PROJECT, 2018
** colle duo 1
** File description:
** Main file
*/

#include "tail.h"

int my_tail(tail_t *tail, int *fds)
{
	char **file = NULL;
	char *file2 = NULL;
	int ret = 0;

	if (tail->verbose && fds[0] == 0)
		my_putstr("==> standard input <==\n");
	for (int i = 0; fds[i] != -2; i = i + 1) {
		file = get_file(tail, fds[i], i, &file2);
		if (file != NULL) {
			tail_verb(tail, i, fds[i]);
			tail_view(file, file2, tail);
		} else {
			tail_verb(tail, i, fds[i]);
			my_puterr(tail->errors[i]);
			ret = 1;
		}
		free_array((void **)file);
		free(file2);
		file2 = NULL;
	}
	return (ret);
}

int main(int ac, char **av)
{
	tail_t *tail = get_struct(ac, av);
	int *fds = NULL;
	int ret;

	if (tail == NULL)
		return (1);
	else if (tail->error == 1)
		return (1);
	fds = get_fds(tail);
	if (fds == NULL)
		return (1);
	ret = my_tail(tail, fds);
	free(fds);
	free_struct(tail);
	return (ret);
}
