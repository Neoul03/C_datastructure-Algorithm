#pragma once
typedef char element;

typedef struct {
	element data;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

treeNode* makeRootNode(element data, treeNode* leftNode, treeNode* rightNode);
void preorder(treeNode* root);
void inorder(treeNode* root);
void postorder(treeNode* root);
