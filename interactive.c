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
	int id, ex;
	char *buffer;
	char *words[1000];
	if (isatty(STDIN_FILENO))
	{
		if (write(STDOUT_FILENO, "$", 1) == -1)
		{
			printf("Failure to write\n");
			freeo(buffer, words);
			exit(90);
		}
	}
	signal(SIGINT, SIG_DFL);
	create_buff(&buffer);
	buffer = custom_getline();
	if (buffer == NULL)
	{

		printf("Failure to read\n");
		freeo(buffer, words);
		exit(91);
	}
	if(feof(stdin))
	{
		return (0);
	}
	termenate(&buffer);
	divide_buffer(words, buffer, ' ');
	terminatewnull(words);
	if(ifexit(words[0]) == 0)
	{
		return (0); 
	}
	handleslash(&words[0]);
	if(ifcommandexsist(words[0]))
	{
		id = fork();
		if (id == -1)
		{	
			freeo(buffer, words);
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
	freeo(buffer, words);
	return (1);
}
