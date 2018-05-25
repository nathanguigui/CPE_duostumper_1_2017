/*
** EPITECH PROJECT, 2018
** tail
** File description:
** File to get the file
*/

#include "tail.h"

int get_ac(char **argv)
{
	int i = 0;

	if (argv == NULL)
		return (0);
	for (i = i; argv[i] != NULL; i = i + 1);
	return (i);
}

char *cat_error(char *temp, char *temp2)
{
	char *res;

	res = my_strcat(temp, temp2);
	free(temp);
	free(temp2);
	return (res);
}

char *get_error_msg(char *name, char *bin)
{
	switch (errno) {
	case 2:
		return (cat_error(my_strcat(bin, ": cannot open '"),
		my_strcat(name, "' for reading: No such file or directory\n")));
	case EACCES:
		return (cat_error(my_strcat(bin, ": cannot open '"),
		my_strcat(name, "' for reading: Permission denied\n")));
	}
	return (my_strcat("Error", ""));
}

int *get_fds(tail_t *tail)
{
	int nb = get_ac(tail->files);
	int *fds = malloc(sizeof(int) * ((nb <= 0 ? 2 : nb + 1)));

	if (nb >= 2 && tail->verbose == 2)
		tail->verbose = 1;
	else if (tail->verbose == 2)
		tail->verbose = 0;
	for (int i = 0; i < nb; i = i + 1) {
		fds[i] = open(tail->files[i], O_RDONLY);
		realloc_tab((void ***)&tail->errors,
		(fds[i] == -1 ? get_error_msg(tail->files[i],
		tail->name): my_strcat("", "")));
	}
	fds[nb] = -2;
	if (nb == 0) {
		fds[0] = 0;
		fds[1] = -2;
	}
	return (fds);
}

char **get_file(tail_t *tail, int fd, int i, char **file2)
{
	DIR *dirent = NULL;
	char **res = NULL;
	char *line = "";

	if (fd != 0 && tail->files != NULL)
		dirent = opendir(tail->files[i]);
	if (fd == -1)
		return (NULL);
	else if (dirent != NULL) {
		closedir(dirent);
		tail->errors[i] = cat_error(my_strcat(tail->name,
		": error reading '"), my_strcat(tail->files[i],
		"': Is a directory\n"));
		return (NULL);
	}
	while (line != NULL) {
		line = get_next_line(fd);
		yolo(&line, file2);
		realloc_tab((void ***)&res, line);
	}
	return (res);
}
