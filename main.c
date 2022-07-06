#include <ncurses.h>
#include <ncursesw/curses.h>
#include "tree.h"
#include "csapp.h"
#include "window.h"

#define MAXARGS 128
#define MAXJOB 20

extern treePointer root;

int main(void) {
	char cmdline[MAXLINE];
	pid_t pid;

	if ((pid = Fork()) == 0) {		/* Child */

	}
	while (1) {

		Fgets(cmdline, MAXLINE, stdin);
	}

	return 0;
}
