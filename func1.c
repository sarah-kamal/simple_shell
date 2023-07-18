#include"shell.h"
void handleslash(char **str)
{
	char *y;
	create_buff(&y);
	c_strcpy("/bin/\0", &y, 6);
	if (*(str)[0] == '/')
	{
		free(y);
		return;
	}
	else
	{
		strcat(y, *str);
	}
	*str = y;
}
