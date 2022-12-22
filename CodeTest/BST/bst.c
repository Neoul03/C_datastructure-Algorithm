#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

void inorder(treeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

// Search x from BST, return node which has x
// Otherwise, return NULL
treeNode* find(treeNode* root, element x) {
	treeNode* p = root;
	if (p == NULL) {
		return NULL;
	}
	if (x == p->key) {
		return p;
	}
	if (x < p->key) {
		return find(p->left, x);
	}
	else {
		return find(p->right, x);
	}
}

// Insert x, check p->key
// If x already exists, do not insert
treeNode* insert(treeNode* bsT, element x) {
	treeNode* p = bsT;
	treeNode* q = NULL;
	while (p != NULL) {
		if (x == p->key) {
			return;
		}
		q = p;
		if (x < p->key){
			p = p->left;
		}
		else {
			p = p->right;
		}
	} 
	
	treeNode* new_node = NULL;
	new_node = (treeNode*)malloc(sizeof(treeNode));

	new_node->key = x;
	new_node->left = NULL;
	new_node->right = NULL;

	if (bsT == NULL) {
		bsT = new_node;
	}
	else if (x < q->key) {
		q->left = new_node;
	}
	else {
		q->right = new_node;
	}

	return;
}

// Delete node which has key
// Will be a long~function
// if 1: key not found
// if 2: terminal node
// if 3: the node has one child
// if 4: the node has two children (solution chose successor from left tree)
void erase(treeNode* root, element key) {
	treeNode* p = root; // 삭제할 key의 노드 포인터
	treeNode* parent; // p의 부모노드 포인터
	parent = (treeNode*)malloc(sizeof(treeNode)); // p가 루트인 경우를 대비하여 p를 가르키는 parent 포인터를 생성
	parent->key = NULL;
	parent->right = root;
	parent->left = root;

	while (p != NULL) {
		if (key == p->key) {
			break;
		}
		parent = p;
		if (key < p->key) {
			p = p->left;
		}
		else {
			p = p->right;
		}
	}


	// 삭제할 노드가 없는 경우
	if (p == NULL) {
		return;
	}

	// 삭제할 노드의 차수가 0인 경우
	if (p->left == NULL && p->right == NULL) {
		if (parent->left == p) {
			parent->left = NULL;
		}
		else{
			parent->right = NULL;
		}
	}

	// 삭제할 노드의 차수가 1인 경우
	else if (p->left == NULL || p->right == NULL){
		
		if (p->left != NULL) {
			if (parent->left == p) {
				parent->left = p->left;
			}
			else {
				parent->right = p->left;
			}
		}

		else {
			if (parent->left == p) {
				parent->left = p->right;
			}
			else {
				parent->right = p->right;
			}
		}
	}

	// 삭제할 노드의 차수가 2인 경우
	else if (p->left != NULL && p->right != NULL) {
		treeNode* q = p->left;
		while (q->right != NULL) { // 왼쪽 서브 트리에서 후계자 노드를 포인터 q로 지정
			q = q->right;
		}
		p->key = q->key;
		if (root == p && p->left->right == NULL) { // 루트의 왼쪽 서브트리에서 가장 큰 값이 루트의 왼쪽 child 일때, 발생되는 문제를 해결
			root->left = root->left->left;
		}
		else{
			erase(p->left, p->key); // 후계자 노드 자리에 대한 2차 재구성
		}
	}

}
