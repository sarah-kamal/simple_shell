#include "shell.h"
/**
 * interactive - Entry point of the program
 * @argc: The number of command line arguments passed
 * @argv: An array of strings representing the command line arguments
 *
 * Return: An integer value indicating the exit status of the program
 */
int interactive(char **environ)
{
	int id, ex, i, numofw;
	char *buffer;
	char **words;
	if (isatty(STDIN_FILENO))
	{
		if (write(STDOUT_FILENO, "$", 1) == -1)
		{
			printf("Failure to write\n");
			exit(90);
		}
	}
	signal(SIGINT, SIG_DFL);
	buffer = custom_getline();
	if (buffer == NULL)
	{

		printf("Failure to read\n");
		free(buffer);
		exit(91);
	}
	if(feof(stdin))
	{
		free(buffer);
		return (0);
	}
	divide_buffer(&words, buffer, ' ', &numofw);
	if(ifexit(words[0]) == 0)
	{
		free(buffer);
                for ( i = 0; i < numofw; i++)
			free(words[i]);
		return (0); 
	}
	handleslash(&words[0]);
	if(ifcommandexsist(words[0]))
	{
		id = fork();
		if (id == -1)
		{	free(buffer);
       			for ( i = 0; i < numofw; i++)
				free(words[i]);
			exit(80);
		}
		if (id == 0)
		{
			ex = execve(words[0], words, environ);
			if (ex == -1)
				 perror("./shell");
		}
		else
		{
			wait(NULL);
		}
	}
	else
	{
		fflush(stdout);
		printf("./shell: No such file or directory\n");
	}
	      free(buffer);
        for ( i = 0; i < numofw; i++)
                 free(words[i]);
	return (1);
}
