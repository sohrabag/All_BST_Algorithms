#include <iostream>
#include <vector>

//Build two BSTs from arr1 and arr2, compare them whether they the same or not?

//data structures
struct TNODE {
	int key;
	TNODE * left;
	TNODE * right;
};

void bstAdd(TNODE** root, int key) {

	if (*root == NULL)
	{
		TNODE * p = new TNODE;
		p->key = key;
		p->left = NULL; p->right = NULL;
		*root = p;
	}
	else if ((*root)->key > key) {
		bstAdd(&(*root)->left, key);
	}
	else if ((*root)->key < key) {
		bstAdd(&(*root)->right, key);
	}
	else {}

	return;
}

int main(void) {

	std::vector<int> arr1 = { 8, 3, 6, 1, 4, 7, 10, 14, 13 };
	std::vector<int> arr2 = { 8, 10, 14, 3, 6, 4, 1, 7, 13 };

	//Build BSTs by inserting arr1 elements into a BST tree. use TNODE structure
	TNODE ** bst1 = new (TNODE*); *bst1 = NULL;
	//insert all the elements of arr1 array into the BST1
	for (unsigned i = 0; i < arr1.size(); ++i){
		bstAdd(bst1, arr1[i]);
	}

	TNODE ** bst2 = new (TNODE*); *bst2 = NULL;
	for (unsigned i = 0; i < arr2.size(); ++i) {
		bstAdd(bst2, arr2[i]);
	}

	return 0;
}