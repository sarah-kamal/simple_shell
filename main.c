#include"shell.h"
/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on successful execution, non-zero value on error.
 */
extern char **environ;
int main(int argc, char *argv[])
{
	int i;
	(void)argv;
	(void)argc;
	do{
		i = interactive(environ);
	}while(i != 0);
	return 0;
}
