/* Name:  Arun Bhusri
 * ID: 5680607
 */
#include <stdlib.h>
#include <stdio.h>
#include "btree.h"

void insert(Node **tree, int val) {
    // IMPLEMENT
    if((*tree) == NULL){
      (*tree) = (Node *)malloc(sizeof(Node));
      (*tree)->data = val;
      (*tree)->left = NULL;
      (*tree)->right = NULL;
    }
    else if(val < (*tree)->data){
        insert(&(*tree)->left, val);
    }
    else {
        insert(&(*tree)->right, val);
    }
}

void printHelper(Node *tree, int n){
	if (tree == NULL){
		return;
	}
	for (int i = 1; i < n; i++){
		printf("  ");
	}
	printf("|-%d\n", tree->data);
	printHelper(tree->left, n+1);
	printHelper(tree->right, n+1);
}


void print(Node *tree) {
	if (!tree){
		return;
	}
  //preorder[root-left-right]
	printf("%d\n", tree->data);
	printHelper(tree->left, 1);
	printHelper(tree->right, 1);
}

void delete(Node *tree) {
    // IMPLEMENT
    if (tree != NULL) {
    	delete(tree->left);
   		delete(tree->right);
   		free(tree);
  	}
}

Node *lookup(Node ** tree, int val) {
    // IMPLEMENT
	if((*tree)==NULL){
    return NULL;
  }
  else if((*tree)->data == val){
    return *tree;
  }
  else if(val <(*tree)->data){
    return lookup(&((*tree)->left),val);
  }
  else{
    return lookup(&((*tree)->right),val);
  }
}



/***** Expected output: *****
7
|-2
  |-1
  |-4
|-10
  |-15
    |-12
      |-11
Found
Not Found
 *****************************/
int main(int argc, char **argv)
{
    Node *root = NULL;
    Node *target = NULL;

    // add nodes
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 10);
    insert(&root, 1);
    insert(&root, 15);
    insert(&root, 12);
    insert(&root, 11);

    // Lets see how the tree looks
    print(root);

    // Check if 4 in the tree
    target = lookup(&root, 4);
    if (target) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    // Check if 44 in the tree
    target = lookup(&root, 44);
    if (target) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    // Now let's free up the space
    delete(root);
}
