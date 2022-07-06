#include "cmd.h"

void eval(char *cmdline) {
	char *argv[MAXARGS];
	char buf[MAXLINE];
	pid_t pid;

	sigset_t mask;
	char* delim;

	strcpy(buf, cmdline);
	parseline(buf, argv);
	if (argv[0] == NULL)
		return;
	/*
	   functions
	   */
	builtin_command(argv);
	return;
}

int parseline(char *buf, char **argv) {
	char *delim;
	int argc;
	
	buf[strlen(buf) - 1] = ' ';
	while (*buf && (*buf == ' '))
		buf++;
	
	argc = 0;
	while ((delim = strchr(buf, ' '))) {
		argv[argc++] = buf;
		*delim = '\0';
		buf = delim + 1;
		while (*buf && (*buf == ' '))
			buf++;
	}
	argv[argc] = NULL;
	if (argc == 0)
		return;
}

int builtin_command(char **argv) {

}
