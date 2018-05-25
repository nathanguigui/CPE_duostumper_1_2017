/*
** EPITECH PROJECT, 2017
** tail_erro.c
** File description:
** 
*/

void tail_erro(tail_t *tail, char *arg)
{
	char **temp;

	result->error = 1;
	if (arg[1] == '-')
		infin_puterr(4, result->name, ": unrecognized option '", arg, "'\n");
	else {
		temp = str_to_word_array(arg, "-");
		infin_puterr(4, result->name, ": invalid option -- '", temp[0], "'\n");
	}
}