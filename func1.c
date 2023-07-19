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
int ifexit(char *str)
{
	if(strcmp(str, "exit\0") == 0)
		return(0);
	return (1);
}
int ifcommandexsist(char *cmd)
{
	if (access(cmd, F_OK | X_OK) == 0)
		return (1);
	else
		return (0);
}
void freeo(char **str, char **str1)
{
	free(*str);
	while (*str1)
	{
		free(*str1);
		str1++;
	}
}

