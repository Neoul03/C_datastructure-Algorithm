#pragma once

typedef int element;

typedef struct treeNode {
	element key;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

void inorder(treeNode* root);

treeNode* find(treeNode* p, element x);
treeNode* insert(treeNode* root, element x);
void erase(treeNode* root, element key);
