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
	int id, readcm, ex;
	char *buffer;
	char *words[1000];
	if (isatty(STDIN_FILENO))
	{
		if (write(STDOUT_FILENO, "$", 1) == -1)
		{
			printf("Failure to write\n");
			exit(90);
		}
	}
	signal(SIGINT, SIG_DFL);
	create_buff(&buffer);
	readcm = read(STDIN_FILENO, buffer, 1024);
	if (readcm == -1)
	{
		printf("Failure to read\n");
		exit(91);
	}
	termenate(&buffer);
	id = fork();
	if (id == -1)
		exit(80);
	if (id == 0)
	{
		divide_buffer(words, buffer, ' ');
		terminatewnull(words);
		handleslash(&words[0]);
		ex = execve(words[0], words, environ);
		if (ex == -1)
			 perror("./shell");
	}
	else
	{
		wait(NULL);
	}
	return 0;
}
