#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_BODY 7200
#define LEN_TITLE 48

typedef struct tree *treePointer;
typedef struct tree {
	int id;
	char title[LEN_TITLE];
	char body[LEN_BODY];
	treePointer leftChild, rightChild;
}tree;

void init_tree(treePointer p);
void add_node(int id, char* title, char* body);
void del_node(int id);
void inorder(treePointer p);
void free_tree(treePointer p);
treePointer getNewNode(int id, char* title, char* body);
treePointer search_id(int id);
treePointer parent_id(int id);
