/*
** EPITECH PROJECT, 2017
** tail
** File description:
** tail_view.c
*/

void tail_verb(tail_t *tail_ag, int i, int fd)
{
	if (fd < 0)
		return;
	else if (tail_ag->verbose && i != 0)
		my_putchar('\n');
	if (tail_ag->verbose && fd != 0)
		infin_put(3, "==> ", tail_ag->files[i], " <==\n");
}

int check_cond(int lines, int i, char **file)
{
	if (lines - i < 0)
		return (0);
	return ((file[lines - i] ? 1 : 0));
}

int epure_size(int lines, int i, char *str_file, tail_t *tail_ag)
{
	int len = my_strlen(str_file);

	if (lines - i < 0 && tail_ag->size_type == 2) {
		my_putstr(str_file);
		return (1);
	} else if (tail_ag->size_type == 1) {
		if (len - i < 0) {
			my_putstr(str_file);
			return (1);
		}
	}
	return (0);
}

void tail_view(char **file, char *str_file, tail_t *tail_ag)
{
	int lines = get_ac(file);
	int ccount = my_strlen(str_file);
	int i = tail_ag->size_count;

	if (epure_size(lines, i, str_file, tail_ag))
		return;
	if (tail_ag->size_type == 2) {
		while (check_cond(lines, i, file)) {
			my_putstr(file[lines - i]);
			i = i - 1;
		}
	} else {
		for (int debug = 0; debug != i; debug = debug + 1)
			ccount = ccount - 1;
		while (str_file[ccount] && ccount <= my_strlen(str_file)) {
			my_putchar(str_file[ccount]);
			ccount += 1;
		}
	}
}
