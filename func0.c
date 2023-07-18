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
	sw = 0;
	while (*buffer != '\0')
	{
		fflush(stdout);
		printf("inwhile");
		if (*buffer == p )
		{
			fflush(stdout);
			printf("InIF");
			create_buff(&words[counter]);
			c_strcpy(buffer, &words[counter], sw);
			counter++;
			sw = 0;
		}
		else
			sw++;
		buffer++;
		y++;
	}
	if (sw > 0)
	{
		fflush(stdout);
		printf("inif2\n");
		create_buff(&words[counter]);
		c_strcpy(buffer - sw, &words[counter], sw);
		counter++;
		 fflush(stdout);
		 printf("words[%i]= %s\n", counter - 1, words[counter - 1]);
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
