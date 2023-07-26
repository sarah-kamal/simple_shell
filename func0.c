#include "shell.h"
char* create_buffer(size_t size) {
    char* buffer = (char*)malloc(size);

    if (buffer == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    return buffer;
}
void create_buff(char **buffer)
{
	 if (buffer == NULL) {
        exit(EXIT_FAILURE);
    }

	*buffer =(char*)malloc(sizeof(char) * 1024);
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
void divide_buffer(char ***word, char *buffer, char p, int *no)
{
	char **words = *word;
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
			words[counter] = create_buffer(sw + 1);
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
		words[counter] = create_buffer(sw + 1);
		c_strcpy(buffer - sw, &words[counter], sw);
		counter++;
	}
	words[counter] = NULL;
	*no = counter;
}
