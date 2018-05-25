/*
** EPITECH PROJECT, 2018
** tail
** File description:
** tools.c
*/

void yolo(char **line, char **file2)
{
	char *temp;
	char *temp2;

	if (*line == NULL)
		return;
	temp = my_strcat(*line, "\n");
	temp2 = my_strcat(*file2, temp);
	free(*line);
	*line = temp;
	free(*file2);
	*file2 = temp2;
}
