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

	if ((pid = Fork()) == 0) {		/* Child */
		
	}


	return 0;
}
