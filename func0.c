#include "shell.h"

void create_buff(char **buffer)
{

	*buffer = malloc(sizeof(char) * 1024);
	if (!(*buffer))
	{
		free(buffer);
		exit(90);
	}
}
void termenate(char **string)
{
	int i;
	char *s;
	s = *string;
	for (i = 0; s[i] != '\n'; i++);
	s[i] = '\0';
}
void c_strcpy(char *source, char **desti, int c)
{
	int i;
	char *dest = *desti;
	for (i = 0; i < c; i++)
	{
		if (source[i] != '\0')
			dest[i] = source[i];
	}
	dest[i] = '\0';
}
void divide_buffer(char **words, char *buffer, char p)
{
	int counter, sw, sp;
	counter = 0;
	sp = 0;
	sw = 0;
	while (*buffer != '\0')
	{
		if (*buffer == p )
		{
			sp = 1;
			buffer++;
			while(*buffer == p)
			{
				buffer++;
				sp++;
			}
			create_buff(&words[counter]);
			c_strcpy(buffer - sw - sp, &words[counter], sw);
			counter++;
			sw = 0;
		}
		else
		{
			sw++;
			buffer++;
		}
	}
	if (sw > 0)
	{
		create_buff(&words[counter]);
		c_strcpy(buffer - sw, &words[counter], sw);
		counter++;
	}

}
void terminatewnull(char **words)
{
	int i;
	i = 0;
	while (words[i])
		i++;
	words[i] = NULL;
}
