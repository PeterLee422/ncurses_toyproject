#include "tree.h"
/*
void init_tree(treePointer p) {
	int res = 1;
	int id;
	char title[48];
	char body[2400];
	FILE *stream = fopen("save.txt", "r");
	if (stream == NULL) {
		fprintf(stderr, "fopen error!\n");
		exit(-1);
	}
	while (res != EOF) {
		res = fscanf(stream, " ", );
	}
}
*/
treePointer root = NULL;

void add_node(int id, char* title, char* body) {
	treePointer p = root;
	if (root == NULL) {
		root = getNewNode(id, title, body);
		return;
	}
	treePointer prev;
	int a = -1;
	while (p != NULL) {
		prev = p;
		if (p->id >= id) {
			p = p->leftChild;
			a = 0;
		}
		else {
			p = p->rightChild;
			a = 1;
		}
	}
	if (a == 0)
		prev->leftChild = getNewNode(id, title, body);
	if (a == 1)
		prev->rightChild = getNewNode(id, title, body);
}

void del_node(int id) {
	treePointer p = search_id(id);
	if (p == NULL)		/* No such ID */
		return;
	if (p == root) {	/* If p is root node */
		free(p);
		root = NULL;
		return;
	}
	treePointer parent = parent_id(id);
	if ((p->leftChild == NULL) && (p->rightChild == NULL)) {	/* Case 1 */
		if (parent->leftChild == p)
			parent->leftChild = NULL;
		else
			parent->rightChild = NULL;
	}
	else if (p->leftChild == NULL){								/* Case 2 */
		if (parent->leftChild == p)
			parent->leftChild = p->rightChild;
		else
			parent->rightChild = p->rightChild;
	}
	else if (p->rightChild == NULL) {							/* Case 3 */
		if (parent->leftChild == p)
			parent->leftChild = p->leftChild;
		else
			parent->rightChild = p->leftChild;
	}
	else {														/* Case 4 */
		treePointer temp = p->rightChild;
		treePointer parent_temp;
		while (temp->leftChild != NULL)
			temp = temp->leftChild;
		parent_temp = parent_id(temp->id);
		if (parent_temp == p) {
			temp->leftChild = p->leftChild;
		}
		else if (temp->rightChild != NULL) {
			parent_temp->leftChild = temp->rightChild;
			temp->leftChild = p->leftChild;
			temp->rightChild = p->rightChild;
		}
		else {
			temp->leftChild = p->leftChild;
			temp->rightChild = p->rightChild;
		}
		if (parent->leftChild == p)
			parent->leftChild = temp;
		else
			parent->rightChild = temp;
	}
	free(p);
}

void inorder(treePointer p) {
	if (p != NULL) {
		inorder(p->leftChild);
		printf("%d -> ", p->id);
		inorder(p->rightChild);
	}
}

void free_tree(treePointer p) {
	if (p == NULL) return;
	free_tree(p->leftChild);
	free_tree(p->rightChild);
	free(p);
}

treePointer getNewNode(int id, char* title, char* body) {
	treePointer pNew = (treePointer)malloc(sizeof(tree));
	if (pNew == NULL) {
		fprintf(stderr, "malloc error!\n");
		exit(1);
	}
	pNew->id = id;
	strcpy(pNew->title, title);
	strcpy(pNew->body, body);
	return pNew;
}

treePointer search_id(int id) {
	treePointer p = root;
	while(p != NULL) {
		if (p->id == id)
			return p;
		else if (p->id > id)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	return NULL;
}

treePointer parent_id(int id) {
	treePointer p = root;
	while (p != NULL) {
		if (((p->leftChild)->id == id) || ((p->rightChild)->id == id))
			return p;
		if (p->id > id)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	return NULL;
}
