#include"shell.h"
#define CHUNK_SIZE 1024

char* custom_getline() {
    char* buffer;
    size_t total_size = 0;
    size_t buffer_size, read_len, len; 
    buffer_size = CHUNK_SIZE;

    buffer = (char*)malloc(buffer_size);
    if (buffer == NULL) {
        perror("Memory allocation error");
       	exit(EXIT_FAILURE);
    }

    while (1) {
        if (fgets(buffer + total_size, buffer_size - total_size, stdin) == NULL) {
            break;
        }

        read_len = strlen(buffer + total_size);
        total_size += read_len;

        if (buffer[total_size - 1] == '\n') {
            break;
        }

        buffer_size += CHUNK_SIZE;
        buffer = (char*)realloc(buffer, buffer_size);

        if (buffer == NULL) {
            perror("Memory reallocation error");
            exit(EXIT_FAILURE);
        }
    }

    len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    return buffer;
}

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
	if (*str != NULL)
		free(str);
	while (*str1)
	{
		free(*str1);
		str1++;
	}
	free(str1);
}

