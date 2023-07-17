#include "shell.h"

char *create_buff()
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (!buffer)
	{
		free(buffer);
		exit(90);
	}
	return (buffer);
}
void termenate(char **string)
{
	int i;
	char *s;
	s = *string;
	for (i = 0; s[i] != '\n'; i++);
	s[i] = '\0';
}
void c_strcpy(char *source, char *dest, int c)
{
	int i;
	for (i = 0; i < c; i++)
	{
		dest[i] = source[i];
	}
	dest[i] = '\0';
	fflush(stdout);
	printf("dest%s\n",dest);
}
void divide_buffer(char **words, char *buffer, char p)
{
	int counter, sw, y;
	counter = 0;
	y = 0;
	while (1)
	{
		if (*buffer == p || y == 0 || *buffer == '\0')
		{
			words[counter] = malloc((sw + 1) * sizeof(char));
			if (words[counter] == NULL)
				exit(90);
			c_strcpy(buffer, words[counter], sw);
			counter++;
			fflush(stdout);
			printf("words[%i]= %s\n",counter, words[counter]);
			sw = 0;
			fflush(stdout);
			if (*buffer == '\0')
				break;
		}
		else
			sw++;
		buffer++;
		y++;
	}

}
void terminatewnull(char **words)
{
	int i;
	char *n;
	i = 0;
	while (words[i])
		i++;
	n = malloc(5 * sizeof(char));
	n = "NULL\0";
	words[i] = n;
}
